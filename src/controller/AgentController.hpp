#pragma once
#include <memory>
#include <string>
#include <iostream>
#include "../llama/LLM.hpp"

class AgentController {
private:
    std::string model_path;
    std::unique_ptr<LLM> model; 
    int flag = 0;
public:
    AgentController(std::string& path) {
        this->model_path = path;
    };   

    int getFlat() {
        return flag;
    };

    void zeroFlag() {
        flag = 0;
    };
    
    std::string generate(std::string prompt) {
        std::string output = model->generate(prompt);
        return output;
    };

    std::string getUserInput() {
        std::string input;
        std::cout << "user: ";
        return input;
    }

    void create()
    {
        model = std::make_unique<LLM>(model_path);
        flag = 1;
    };
};