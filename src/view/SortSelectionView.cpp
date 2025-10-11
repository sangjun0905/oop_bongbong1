#include "SortSelectionView.hpp"

#include <iostream>
#include <string>

std::string SortSelectView::display() {

    output = " --- Sorting Option ---\n"
            "1. Sort by Name\n"
            "2. Sort by StudentID\n"
            "3. Sort by BirthYear\n"
            "4. Sort by Department\n"
            "> ";
    std::cout << output; 
    return "PROMPT:SORT_MENU(1..4)";
};

std::string SortResultView::display(){
    output = "Sorting completed";
    std::cout << output << std::endl;
    return "RESULT:SORT:COMPLETED";
};
