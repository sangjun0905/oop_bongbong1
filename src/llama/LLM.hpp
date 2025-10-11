#pragma once

#include <string>
#include <vector>
#include "llama.h"

class LLM {
public:
    LLM(const std::string& model_path);
    ~LLM();
    std::string generate(const std::string& prompt);

private:
    llama_model* model_ = nullptr;
    llama_context* ctx_ = nullptr;
    int n_ctx_ = 0; // 컨텍스트 크기를 저장할 멤버 변수

};

