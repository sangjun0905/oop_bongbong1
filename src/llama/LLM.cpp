#include "LLM.hpp"
#include <stdexcept>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>


// This code was written with a lot of reference to llama.cpp/examples/simple.cpp

#define MAX_GENERATE_TOKENS 256

void empty_log_callback(ggml_log_level level, const char * message, void * user_data) {
    // 빈 콜백
}

LLM::LLM(const std::string& model_path) {

    //복잡한 로그가 터미널에 뜨지 않게 빈 콜백 설정
    llama_log_set(empty_log_callback, nullptr);

    // llama 백엔드 로드
    ggml_backend_load_all();

    // 모델 로드 
    // 파라미터 기본값 사용
    llama_model_params model_params = llama_model_default_params();

    //모델 파일 경로와 기본 파라미터로 모델 로드
    model = llama_model_load_from_file(model_path.c_str(), model_params);
    
    if (model == nullptr) {
        throw std::runtime_error("error: unable to load model\n");
    }

    // 컨텍스트 생성
    n_ctx_ = llama_model_n_ctx_train(model); 

    llama_context_params ctx_params = llama_context_default_params();
    // n_ctx is the context size
    ctx_params.n_ctx = n_ctx_;
    // enable performance counters
    ctx_params.no_perf = false;

    ctx = llama_init_from_model(model, ctx_params);
    if (ctx == nullptr) {
        throw std::runtime_error(" error: failed to create the llama_context\n");
    }

    auto sparams = llama_sampler_chain_default_params();
    sparams.no_perf = false;
    smpl = llama_sampler_chain_init(sparams);

    llama_sampler_chain_add(smpl, llama_sampler_init_greedy());

    std::cout << "Model and context loaded successfully.\n" << std::endl;
}

// 소멸자: 리소스 정리
LLM::~LLM() {
    if (smpl)   llama_sampler_free(smpl);
    if (ctx)  llama_free(ctx);
    if (model) llama_model_free(model);
    llama_backend_free();
    std::cout << "LLama ended.\n\n" << std::endl;
}

// 프롬프트를 받아 텍스트 생성
std::string LLM::generate(const std::string& prompt) {

    const llama_vocab * vocab = llama_model_get_vocab(model);

    int n_predict = MAX_GENERATE_TOKENS; //생성할 최대 토큰 수
    const int n_prompt = -llama_tokenize(vocab, prompt.c_str(), prompt.size(), NULL, 0, true, true);

    // 1) 토큰화 (vocab 사용)
    std::vector<llama_token> prompt_tokens(n_prompt);

    if (llama_tokenize(vocab, prompt.c_str(), prompt.size(), prompt_tokens.data(), prompt_tokens.size(), true, true) < 0) {
        throw std::runtime_error("error: failed to tokenize the prompt\n");
    }

    //2) 메모리(KV 캐시) 초기화
    llama_memory_clear(llama_get_memory(ctx), true);

    // 3) 프롬프트 처리 배치 구성 및 디코드     
    llama_batch batch = llama_batch_get_one(prompt_tokens.data(), prompt_tokens.size());

    if (llama_model_has_encoder(model)) {
        if (llama_encode(ctx, batch)) {
            throw std::runtime_error("failed to eval\n");
        }

        llama_token decoder_start_token_id = llama_model_decoder_start_token(model);
        if (decoder_start_token_id == LLAMA_TOKEN_NULL) {
            decoder_start_token_id = llama_vocab_bos(vocab);
        }

        batch = llama_batch_get_one(&decoder_start_token_id, 1);
    }

    // 4) 생성 루프 
    std::string result = "";
    int n_decode = 0;
    llama_token new_token_id;

    for (int n_pos = 0; n_pos + batch.n_tokens < n_prompt + n_predict; ) {
        // evaluate the current batch with the transformer model
        if (llama_decode(ctx, batch)) {
            throw std::runtime_error("failed to eval, return code %d\n");
        }

        n_pos += batch.n_tokens;

        // sample the next token
        {
            new_token_id = llama_sampler_sample(smpl, ctx, -1);

            // is it an end of generation?
            if (llama_vocab_is_eog(vocab, new_token_id)) {
                break;
            }

            char buf[MAX_GENERATE_TOKENS];
            int n = llama_token_to_piece(vocab, new_token_id, buf, sizeof(buf), 0, true);
            if (n < 0) {
                throw std::runtime_error("error: failed to convert token to piece\n");
            }
            std::string s(buf, n);
            result += s;

            // prepare the next batch with the sampled token
            batch = llama_batch_get_one(&new_token_id, 1);

            n_decode += 1;
        }
    }

    return result;
}