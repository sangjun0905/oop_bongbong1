#pragma once

#include "../model/StudentList.hpp"
#include "../llama/LlamaService.hpp" // LlamaService 헤더 포함
#include <memory>
#include <iostream> 
#include <string>


class ChatbotController {
private:
    // ... 기존 멤버 변수들 ...
    std::unique_ptr<LlamaService> llama_service_; 

public:
    ChatbotController() {
        // 컨트롤러가 생성될 때, LlamaService 객체도 함께 생성합니다.
        // 사용할 모델 파일 이름을 전달합니다.
        std::string model_path = "..\\external\\llama.cpp\\models\\LFM2-2.6B-Q4_K_M.gguf";
        llama_service_ = std::make_unique<LlamaService>(model_path);
    }

    // View에서 호출할 함수
    void handleUserInput(const std::string& user_question);
};
