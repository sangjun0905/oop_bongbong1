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
    sortedStudentList = studentList;  
    auto& students = sortedStudentList.getAllStudents(); 
    std::sort(students.begin(), students.end(),
              [](const Student& a, const Student& b) {
                  return a.getName() < b.getName();
              });
    sortView.displaySortResult(sortedStudentList);
    return sortedStudentList;
}

StudentList& SortController::sortByStudentId(StudentList& studentList) {
    sortedStudentList = studentList;
    auto& students = sortedStudentList.getAllStudents();
    std::sort(students.begin(), students.end(),
              [](const Student& a, const Student& b) {
                  return a.getStudentId() < b.getStudentId();
              });
    sortView.displaySortResult(sortedStudentList);
    return sortedStudentList;
}

StudentList& SortController::sortByBirth(StudentList& studentList) {
    sortedStudentList = studentList;
    auto& students = sortedStudentList.getAllStudents();
    std::sort(students.begin(), students.end(),
              [](const Student& a, const Student& b) {
                  return a.getBirthYear() < b.getBirthYear();
              });
    sortView.displaySortResult(sortedStudentList);
    return sortedStudentList;
}

StudentList& SortController::sortByDepartment(StudentList& studentList) {
    sortedStudentList = studentList;
    auto& students = sortedStudentList.getAllStudents();
    std::sort(students.begin(), students.end(),
              [](const Student& a, const Student& b) {
                  return a.getDepartment() < b.getDepartment();
              });
    sortView.displaySortResult(sortedStudentList);
    return sortedStudentList;
}

