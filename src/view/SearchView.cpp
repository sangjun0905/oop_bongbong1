#include <iostream>

class SortingView {
public :
    char display() {
        char input[10];
        std::cout << "- Search -" << std::endl;
        std::cout << "1. Search by name" << std::endl;
        std::cout << "2. Search by student ID" << std::endl;
        std::cout << "3. Search by admission year" << std::endl;
        std::cout << "4. Search by birth year" << std::endl;
        std::cout << "5. Search by department name" << std::endl;
        std::cout << "6. List ALL" << std::endl;
        std::cout << "7. Back to main menu" << std::endl;
        std::cout << "> ";
        // input 받기
        std::cin >> input;

        while (input[0] < '1' || input[0] > '7'){
            std::cout << "Please enter a number between 1 and 7." << std::endl;
            std::cin >> input;
        } // input이 1~7가 아니면 다시 입력
  
        return input[0];
    }
};