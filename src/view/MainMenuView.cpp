#include "MainMenuView.hpp"
#include <iostream>
#include <string>

char MainMenuView::display() {
    std::string input;
    
    do {
        std::cout << "1. Insertion" << std::endl;
        std::cout << "2. Search" << std::endl;
        std::cout << "3. Sorting Option" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "> ";
        
        std::cin >> input;
    } while (check_input(input));

    return input[0];
}

int MainMenuView::check_input(const std::string& input) {
    if (input.length() == 1 && (input[0] >= '1' && input[0] <= '5')) {
        return 0; // Valid input
    }

    std::cout << "Try again!" << std::endl;
    return 1; // Invalid input
}