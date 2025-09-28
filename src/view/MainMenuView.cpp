#include <iostream>

class MainMenuView {
public:
    char display() {
        char input[10];
        
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

    int check_input(char* input) {
        if (input[0] == '1') return 0;
        if (input[0] == '2') return 0;
        if (input[0] == '3') return 0;
        if (input[0] == '4') return 0;

        std::cout << "Try again!" << std::endl;
        return 1;
    }
};