#include "SortingModule.hpp"
#include <iostream>
#include <iomanip> // setw()을 사용하여 출력 형식을 맞추기 위해 포함

void SortingResultView::displaySearchResults(const std::vector<Student>& results) {

    // setw : 너비를 고정해서 출력
    std::cout << std::left << std::setw(16) << "Name"
              << std::setw(12) << "Student ID"
              << std::setw(25) << "Department"
              << std::setw(12) << "Birth Year"
              << std::setw(15) << "Tel"
              << "\n";
    std::cout << "================================================================================\n";

    for (const auto& student : results) {
            std::cout << std::left << std::setw(16) << student.getName()
                      << std::setw(12) << student.getStudentID()
                      << std::setw(25) << student.getDepartment()
                      << std::setw(12) << student.getBirthYear()
                      << std::setw(15) << student.getTel()
                      << "\n";
        }
    
    std::cout << "================================================================================\n\n";
}