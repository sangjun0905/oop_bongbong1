#pragma once
#include <stdexcept>
#include <iostream>
#include <memory>
#include <string>
#include <iostream>
#include "../llama/LLM.hpp"
#include "../view/AgentView.hpp"

class AgentController {
private:
    const std::string& model_path;
    std::unique_ptr<LLM> model; 
    int flag = 0;
    AgentView agentView;
public:
    //before create method is executed, store the model path 
    AgentController(const std::string& path) : model_path(path) {
        flag = 0;
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

    int getFlag() {
        return flag;
    };

    void zeroFlag() {
        flag = 0;
    };
    
    

    std::string getUserInput() {
        std::string input;
        input = agentView.display();
        return input;
    }

    
};