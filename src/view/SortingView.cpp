#include <iostream>

class SortingView {
public :
    char display() {
        char input[10];
        do {
            std::cout << "1. Sort by name" << std::endl;
            std::cout << "2. Sort by s-id" << std::endl;
            std::cout << "3. Sort by birth" << std::endl;
            std::cout << "4. Sort by dept" << std::endl;
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

        std::cout << "Please enter a number between 1 and 4." << std::endl;
        return 1;
    }
};