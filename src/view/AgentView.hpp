#ifndef AGENTVIEW_HPP
#define AGENTVIEW_HPP

#include <iostream>
#include <string>

class AgentView {

public : 
    
    std::string display()
    {
        std::string input;
        std::cout << "user: ";
        std::getline(std::cin, input);
        return input;

    }
    void printResult(std::string result){
        std::cout << "LLM responce: " << result << std::endl;

    }
};

#endif