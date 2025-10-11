#pragma once 

#include "View.hpp"
#include <iostream>
#include <string>

class MainMenuView : public View{
public:
    std::string display() override {
        output = "--- Main Menu ---\n" 
                "1. Insertion\n"
                "2. Search\n"
                "3. Sorting Option\n"
                "4. Exit\n"
                "5. Agent Mode\n"
                "> ";
        std::cout << output;
        return output;    
    };
};
