#pragma once
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
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
    std::string generate(const std::string& prompt) {
        if (!model) {
            throw std::logic_error("Agent model is not initialized. Call create() first.");
        }
        return model->generate(prompt);
    };

    int getFlat() {
        return flag;
    };

    void zeroFlag() {
        flag = 0;
    };
    
    

    std::string getUserInput() {
        std::cout << "user: " << std::flush;
        std::string input;
        std::getline(std::cin, input);
        return input;
    }

    
};
