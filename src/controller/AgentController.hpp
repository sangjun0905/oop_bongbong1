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
    //before create method is executed, store the model path 
    AgentController(std::string& path) {
        this->model_path = path;
    };

    //after constructor is executed, create LLM instance
    void create()
    {
        model = std::make_unique<LLM>(model_path);
        flag = 1;
    };   

    //after create method is executed, use generate method
    std::string generate(std::string prompt) {
        std::string output = model->generate(prompt);
        return output;
    };

    int getFlat() {
        return flag;
    };

    void zeroFlag() {
        flag = 0;
    };
    
    

    std::string getUserInput() {
        std::string input;
        std::cout << "user: ";
        return input;
    }

    
};