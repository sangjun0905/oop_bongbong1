#pragma once 

#include "View.hpp"
#include <iostream>
#include <string>

class ErrorView : public View{
public:
    std::string display() override {
        output = "Invalid Input";
        std::cout << output << std::endl;
        return output;
    }
};
