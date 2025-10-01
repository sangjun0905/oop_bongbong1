#include "SearchModule.hpp"
#include <iostream>
#include <iomanip> // setw()을 사용하여 출력 형식을 맞추기 위해 포함

void SearchResultView::displaySearchResults(const std::vector<Student>& results) {

    // setw : 너비를 고정해서 출력
    std::cout << std::left << std::setw(16) << "Name"
              << std::setw(12) << "Student ID"
              << std::setw(25) << "Department"
              << std::setw(12) << "Birth Year"
              << std::setw(15) << "Tel"
              << "\n";
    std::cout << "================================================================================\n";

    for (const auto& studentmodel : results) {
            std::cout << std::left << std::setw(16) << studentmodel.getName()
                      << std::setw(12) << studentmodel.getStudentID()
                      << std::setw(25) << studentmodel.getDepartment()
                      << std::setw(12) << studentmodel.getBirthYear()
                      << std::setw(15) << studentmodel.getTel()
                      << "\n";
        }
    
    std::cout << "================================================================================\n\n";
}