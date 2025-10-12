#pragma once 

#include "View.hpp"
#include <string>

class ErrorView : public View{
public:
    std::string display() override {
        std::string output = "Invaild Input";
        std::cout << output << std::endl;
        return output;
    };
};
