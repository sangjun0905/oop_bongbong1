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
        llama_service_ = std::make_unique<LlamaService>("lfm2-2.6b-q4_k_m.gguf");
    }

    // View에서 호출할 함수
    void handleUserInput(const std::string& user_question);
};