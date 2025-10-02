#include <iostream>
#include "SortView.hpp"

char SortView::display() {
    std::string input;
    
    do {
        std::cout << " - Sorting Option" << std::endl;
        std::cout << "1. Sort by Name" << std::endl;
        std::cout << "2. Sort by Student ID" << std::endl;
        std::cout << "3. Sort by Birth Year" << std::endl;
        std::cout << "4. Sort by Department name" << std::endl;
        std::cout << "> ";
        
        std::cin >> input;
    } while (check_input(input));

    return input[0];
}

int SortView::check_input(const std::string& input) {
    if (input.length() == 1 && (input[0] >= '1' && input[0] <= '4')) {
        return 0; // Valid input
    }

    std::cout << "Try again!" << std::endl;
    return 1; // Invalid input
}

void SortView::displaySortResult(StudentList& studentList) {
    std::vector<Student> students = studentList.getAllStudents();

    std::cout << "\n===== Sorted Result =====" << std::endl;
    for (const auto& s : students) {
        std::cout << "Name: "       << s.getName()
                  << ", ID: "       << s.getStudentId()
                  << ", Birth: "    << s.getBirthYear()
                  << ", Dept: "     << s.getDepartment()
                  << ", Tel: "      << s.getTel()
                  << std::endl;
    }
    std::cout << "=========================\n" << std::endl;
}