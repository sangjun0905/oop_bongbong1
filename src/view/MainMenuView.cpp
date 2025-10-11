#include "MainMenuView.hpp"

#include <iostream>
#include <string>

std::string MainMenuView::display() { 
    
    output = "--- Main Menu ---\n" 
            "1. Insertion\n"
            "2. Search\n"
            "3. Sorting Option\n"
            "4. Exit\n"
            "5. Agent Mode\n"
            "> ";
    std::cout << output; 
    return "PROMPT:MAIN_MENU(1..5)";
}
