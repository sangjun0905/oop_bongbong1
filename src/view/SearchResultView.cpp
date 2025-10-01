#include "../model/StudentList.hpp"
#include "../model/Student.hpp"
#include <iostream>
#include <iomanip> // setw()을 사용하여 출력 형식을 맞추기 위해 포함

void displaySearchResults(StudentList &studentList) {

    // setw : 너비를 고정해서 출력
    std::cout << std::left << std::setw(16) << "Name"
              << std::setw(12) << "Student ID"
              << std::setw(25) << "Department"
              << std::setw(12) << "Birth Year"
              << std::setw(15) << "Tel"
              << "\n";
    std::cout << "================================================================================\n";

    
    std::cout << "================================================================================\n\n";
}