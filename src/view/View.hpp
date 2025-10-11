#pragma once 

#include <string> 
#include <iostream>

class View { 
public: 

    std::string output; 
    
    View() : output("") {} 
    
    virtual ~View() = default; 

    virtual void display() { 
        std::cout << output << std::endl;  
    }
    
};