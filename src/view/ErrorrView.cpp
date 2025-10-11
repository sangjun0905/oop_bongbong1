#pragma once 

#include "View.hpp"

#include <string>

class ErrorView : public View{
public:
    std::string output = "Invaild Input";
    std::string display() override {
        std::cout << output << std::endl;
        return "ERROR:INVALID_INPUT";
    };
};
