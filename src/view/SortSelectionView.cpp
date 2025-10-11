#include "SortSelectionView.hpp"

#include <iostream>
#include <string>

namespace view::sort   {

void SortSelectView::display() {

    output = " --- Sorting Option ---\n"
            "1. Sort by Name\n"
            "2. Sort by StudentID\n"
            "3. Sort by BirthYear\n"
            "4. Sort by Department\n"
            "> ";
    std::cout << output; 
};

void SortResultView::display(){
    output = "Sorted Complete";
    std::cout << output << std::endl;
};

} 