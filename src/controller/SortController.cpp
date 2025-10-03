#include "SortController.hpp"
#include <algorithm>
#include <iostream>


SortController::SortController(SortView& sortView, StudentList& studentList): sortView(sortView) {
    char userSelect = sortView.display();

    switch (userSelect) {
        case '1':
            sortByName(studentList);
            break;
        case '2':
            sortByStudentId(studentList);
            break;
        case '3':
            sortByBirth(studentList);
            break;
        case '4':
            sortByDepartment(studentList);
            break;
        default:
            std::cout << "잘못된 입력입니다." << std::endl;
            break;
    }
}
SortController::~SortController() {}

StudentList& SortController::sortByName(StudentList& studentList) {  
    auto& students = studentList.getAllStudents(); 
    std::sort(students.begin(), students.end(),
              [](const Student& a, const Student& b) {
                  return std::string(a.getName()) < std::string(b.getName());
              });
    sortView.displaySortResult(studentList);
    return studentList;
}

StudentList& SortController::sortByStudentId(StudentList& studentList) {
    auto& students = studentList.getAllStudents();
    std::sort(students.begin(), students.end(),
              [](const Student& a, const Student& b) {
                  return std::string(a.getStudentId()) < std::string(b.getStudentId());
              });
    sortView.displaySortResult(studentList);
    return studentList;
}

StudentList& SortController::sortByBirth(StudentList& studentList) {
    auto& students = studentList.getAllStudents();
    std::sort(students.begin(), students.end(),
              [](const Student& a, const Student& b) {
                  return a.getBirthYear() < b.getBirthYear();
              });
    sortView.displaySortResult(studentList);
    return studentList;
}

StudentList& SortController::sortByDepartment(StudentList& studentList) {
    auto& students = studentList.getAllStudents();
    std::sort(students.begin(), students.end(),
              [](const Student& a, const Student& b) {
                  return std::string(a.getDepartment()) < std::string(b.getDepartment());
              });
    sortView.displaySortResult(studentList);
    return studentList;
}

