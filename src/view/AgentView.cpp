#include "AgentView.hpp"

std::string display() {

    std::string input;
    std::cout << "user: ";
    std::getline(std::cin, input);
    return input;
}

void AgentView::printResult(std::string result)
{
    std::cout << "LLM responce: " << result << std::endl;    
};