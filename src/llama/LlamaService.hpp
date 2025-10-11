#ifndef LLAMA_SERVICE_HPP
#define LLAMA_SERVICE_HPP

#include <string>
#include <vector>
#include "llama.h"

class LlamaService {
public:
    LlamaService(const std::string& model_path);
    ~LlamaService();
    std::string ask(const std::string& prompt);

private:
    llama_model* model_ = nullptr;
    llama_context* ctx_ = nullptr;
    int n_ctx_ = 0; // 컨텍스트 크기를 저장할 멤버 변수

    // 복사 및 대입 방지
    LlamaService(const LlamaService&) = delete;
    LlamaService& operator=(const LlamaService&) = delete;
};

#endif // LLAMA_SERVICE_HPP