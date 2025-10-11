#include "MainMenuView.hpp"

#include <iostream>
#include <string>

namespace view::mainmenu {

std::string MainMenuView::display() { 
    
    output = "--- Main Menu ---\n" 
            "1. Insertion\n"
            "2. Search\n"
            "3. Sorting Option\n"
            "4. Exit\n"
            "5. Agent Mode\n"
            "> ";
    std::cout << output; 
}

std::string MainMenuErrorView::display() {
    output = "Try again!";
    std::cout << output << std::endl;
}

} // namespace view::mainmenu