#pragma once 

#include "View.hpp"
#include <iostream>
#include <string>

class SortSelectView : public View{
public:
    std::string display() override {
    output = " --- Sorting Option ---\n"
        "1. Sort by Name\n"
        "2. Sort by StudentID\n"
        "3. Sort by BirthYear\n"
        "4. Sort by Department\n"
        "> ";
    std::cout << output; 
    return output;
    };
};

class SortResultView : public View{
public:
    std::string display() override {
        output = "Sorting completed";
        std::cout << output << std::endl;
        return output + " Main";
    };
};
