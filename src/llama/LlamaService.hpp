#ifndef LLAMA_SERVICE_HPP
#define LLAMA_SERVICE_HPP

#include <string>

class LlamaService {
public:
    LlamaService() {};
    // 생성자: 모델 파일 경로 등을 초기화할 수 있습니다.
    LlamaService(const std::string& model_path);

    /**
     * @brief LLM에게 질문(프롬프트)을 던지고 답변을 받아옵니다.
     * @param prompt LLM에게 전달할 상세한 프롬프트 문자열
     * @return LLM이 생성한 답변 문자열
     */
    std::string ask(const std::string& prompt);

private:
    std::string llama_executable_path_;
    std::string model_path_;
};

#endif // LLAMA_SERVICE_HPP