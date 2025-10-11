#pragma once 

#include <string> 
#include <iostream>

#include "../model/StudentList.hpp"

class ResultView { 
public: 

    StudentList list;
    std::string output; 
    
    ResultView() : output("") {} 
    
    virtual ~ResultView() = default; 

    virtual void display(StudentList list) { 
        std::cout << output << std::endl;  
    }
    
};