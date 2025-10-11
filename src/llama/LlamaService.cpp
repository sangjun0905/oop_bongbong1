#include "LlamaService.hpp"
#include <stdexcept>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

void empty_log_callback(ggml_log_level level, const char * message, void * user_data) {
    // 빈 콜백
}

LlamaService::LlamaService(const std::string& model_path) {

    llama_log_set(empty_log_callback, nullptr);

    // ggml/llama 백엔드 초기화
    llama_backend_init();

    // 모델 로드
    llama_model_params model_params = llama_model_default_params();
    model_ = llama_model_load_from_file(model_path.c_str(), model_params);
    if (model_ == nullptr) {
        throw std::runtime_error("LlamaService: Failed to load model from " + model_path);
    }

    // 컨텍스트 생성
    n_ctx_ = 2048; // 필요시 조정 가능
    llama_context_params ctx_params = llama_context_default_params();
    ctx_params.n_ctx = n_ctx_;

    ctx_ = llama_init_from_model(model_, ctx_params);
    if (ctx_ == nullptr) {
        throw std::runtime_error("LlamaService: Failed to create context");
    }
    std::cout << "Model and context loaded successfully.\n" << std::endl;
}

// 소멸자: 리소스 정리
LlamaService::~LlamaService() {
    if (ctx_)   llama_free(ctx_);
    if (model_) llama_model_free(model_);
    llama_backend_free();
    std::cout << "LLama ended.\n\n" << std::flush;
}

// 간단한 Greedy 생성
std::string LlamaService::ask(const std::string& prompt) {
    const llama_vocab * vocab = llama_model_get_vocab(model_);

    // 1) 토큰화 (vocab 사용)
    std::vector<llama_token> tokens(prompt.size() + 16);
    int n_tokens = llama_tokenize(
        vocab,
        prompt.c_str(),
        static_cast<int32_t>(prompt.size()),
        tokens.data(),
        static_cast<int32_t>(tokens.size()),
        /*add_special*/ true,
        /*parse_special*/ false);
    if (n_tokens < 0) {
        throw std::runtime_error("LlamaService: Tokenization failed.");
    }
    tokens.resize(n_tokens);
    if (n_tokens == 0) {
        // 빈 프롬프트 등으로 토큰이 0개라면 디코드를 수행할 수 없습니다.
        return std::string();
    }

    // 2) 메모리(KV 캐시) 초기화
    llama_memory_clear(llama_get_memory(ctx_), /*data*/ true);

    // 3) 프롬프트 처리 배치 구성 및 디코드
    llama_batch batch = llama_batch_init(n_tokens, /*embd*/ 0, /*n_seq_max*/ 1);
    for (int i = 0; i < n_tokens; ++i) {
        batch.token[i]     = tokens[i];
        batch.pos[i]       = i;
        batch.n_seq_id[i]  = 1;
        batch.seq_id[i][0] = 0;
        batch.logits[i]    = (i == n_tokens - 1) ? 1 : 0; // 마지막만 로짓 출력
    }

    batch.n_tokens = n_tokens;

    {
        const int32_t ret = llama_decode(ctx_, batch);
        if (ret != 0) {
            llama_batch_free(batch);
            throw std::runtime_error("LlamaService: llama_decode failed for prompt (code=" + std::to_string(ret) + ")");
        }
    }

    // 4) 생성 루프 (Greedy)
    std::string result;
    int n_cur = n_tokens;
    const int max_new_tokens = 64;
    const int32_t n_vocab = llama_vocab_n_tokens(vocab);

    while (n_cur < n_ctx_ && (n_cur - n_tokens) < max_new_tokens) {
        // 마지막 디코드의 로짓 가져오기 (연속 배열, 행 0이 최근 출력)
        float * logits = llama_get_logits(ctx_);
        if (logits == nullptr || n_vocab <= 0) {
            llama_batch_free(batch);
            throw std::runtime_error("LlamaService: Failed to get logits for generation");
        }

        // Greedy 선택
        int32_t new_token_id = static_cast<int32_t>(
            std::max_element(logits, logits + n_vocab) - logits);

        // EOS면 종료
        if (new_token_id == llama_vocab_eos(vocab)) {
            break;
        }

        // 토큰 -> 텍스트 조각 변환
        char piece[64];
        int n_chars = llama_token_to_piece(
            vocab,
            new_token_id,
            piece,
            static_cast<int32_t>(sizeof(piece)),
            /*lstrip*/ 0,
            /*special*/ false);
        if (n_chars > 0) {
            result.append(piece, n_chars);
        }
        /*
         // 개행이 나오면 한 줄 답변으로 종료
        if (result.find('\n') != std::string::npos) {
            break;
        }*/

        // 다음 토큰 1개만 디코드 요청 (로짓 출력)
        batch.n_tokens      = 1;
        batch.token[0]      = new_token_id;
        batch.pos[0]        = n_cur;
        batch.n_seq_id[0]   = 1;
        batch.seq_id[0][0]  = 0;
        batch.logits[0]     = 1;

        ++n_cur;

        const int32_t ret = llama_decode(ctx_, batch);
        if (ret != 0) {
            llama_batch_free(batch);
            throw std::runtime_error("LlamaService: llama_decode failed for generation (code=" + std::to_string(ret) + ")");
        }
    }

    llama_batch_free(batch);
    /*
    // 첫 줄만 반환해 간결하게
    if (auto pos = result.find('\n'); pos != std::string::npos) {
        result.erase(pos);
    }
    */
    return result;
}
