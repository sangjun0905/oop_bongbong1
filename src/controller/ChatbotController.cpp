#include "ChatbotController.hpp"

void ChatbotController::handleUserInput(const std::string& user_question) {
    // 1. (생략) DB에서 사용자 질문에 필요한 데이터를 조회합니다. (예: "김철수"의 성적)
    // StudentData student_data = student_list_model->find("김철수");
    
    // 2. 프롬프트 엔지니어링: 상세한 메모(프롬프트)를 만듭니다.
    std::string prompt;
    prompt += "You are a helpful assistant trained by Liquid AI\n";
    prompt += "Answer the question shortly and if the answer is over, stop immediately.\n Don't repeat same sentence. \n";
    prompt += "Question: "+ user_question + "\nAnswer:";
    
    /*
    std::string prompt = "You are a calculator. Answer only the integer value and then stop. Do not generate a new question.\n\n"
                     "Question: " + user_question + "\nAnswer:";
    */
    // 3. LlamaService를 통해 LLM에게 질문하고 답변을 받습니다.
    std::cout << "Asking LLM..." << std::endl;
    std::string ai_response = llama_service_->generate(prompt);
    std::cout << "LLM Response: " << "\n" << ai_response << "\n\n";

    // 4. (생략) 받은 답변(ai_response)을 ChatbotView에 업데이트하도록 지시합니다.
    // chatbot_view->addMessage("AI", ai_response);
}