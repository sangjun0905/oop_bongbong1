#include "SortController.hpp"
#include <algorithm>


SortController::SortController(SortView& sortView) : sortView(sortView) {}
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

StudentList& SortController::sortByStudnetId(StudentList& studentList) {
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

