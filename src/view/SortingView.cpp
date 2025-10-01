#include <iostream>

class SortingView {
public :
    char display() {
        char input[10];
        std::cout << "- Sorting Option" << std::endl;
        std::cout << "1. Sort by name" << std::endl;
        std::cout << "2. Sort by s-id" << std::endl;
        std::cout << "3. Sort by birth" << std::endl;
        std::cout << "4. Sort by dept" << std::endl;
        std::cout << "5. Go back to main menu" << std::endl;
        std::cout << "> ";
        // input 받기
        std::cin >> input;

        while (input[0] < '1' || input[0] > '5'){
            std::cout << "Please enter a number between 1 and 5." << std::endl;
            std::cin >> input;
        } // input이 1~5가 아니면 다시 입력
  
        return input[0];
    }
    SortingView();
};