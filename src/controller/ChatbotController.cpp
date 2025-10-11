#include "ChatbotController.hpp"

void ChatbotController::handleUserInput(const std::string& user_question) {
    // 1. (생략) DB에서 사용자 질문에 필요한 데이터를 조회합니다. (예: "김철수"의 성적)
    // StudentData student_data = student_list_model->find("김철수");
    
    // 2. 프롬프트 엔지니어링: 상세한 메모(프롬프트)를 만듭니다.
    /*
    std::string prompt = "너는 학생 정보 시스템의 친절한 도우미야.\n";
    prompt += "[데이터] 학생 이름: 김철수, 성적: C++ A+\n"; // 실제로는 student_data를 이용
    prompt += "[질문] " + user_question + "\n";
    prompt += "[답변]\n";
    */

    std::string prompt;// 임시로 user_question만 프롬프트로 사용
    prompt += "You are a helpful assistant.\n";
    prompt += "Answer concisely with only the final answer. No explanations.\n";
    prompt += "Q: " + user_question + "\n";

    // 3. LlamaService를 통해 LLM에게 질문하고 답변을 받습니다.
    std::cout << "Asking LLM...";
    std::string ai_response = llama_service_->ask(prompt);
    std::cout << "LLM Response: " << ai_response << std::endl;

    // 4. (생략) 받은 답변(ai_response)을 ChatbotView에 업데이트하도록 지시합니다.
    // chatbot_view->addMessage("AI", ai_response);
}