#pragma once 

#include <string> 
#include <iostream>

class View { 
public: 

    std::string output; 
    
    View() : output("") {} 
    
    virtual ~View() = default; 

    virtual std::string display() { 
        std::cout << output << std::endl;
        return output;  
    }
    
};