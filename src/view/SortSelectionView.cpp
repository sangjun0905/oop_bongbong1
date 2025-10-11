#include "SortSelectionView.hpp"

#include <iostream>
#include <string>

namespace view::sort   {

std::string SortSelectView::display() {

    output = " --- Sorting Option ---\n"
            "1. Sort by Name\n"
            "2. Sort by StudentID\n"
            "3. Sort by BirthYear\n"
            "4. Sort by Department\n"
            "> ";
    std::cout << output; 
};

std::string SortResultView::display(){
    output = "Sorting completed";
    std::cout << output << std::endl;
};

} 