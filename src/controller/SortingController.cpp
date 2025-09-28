#include "SortingController.hpp"
#include <iostream>
#include <algorithm> // std::sort 사용
#include "Student.hpp" 

SortingController::SortingController(Views* v, Student_Model* m)
    : views(v), model(m) {}

// SortingController의 메인 실행 함수
std::vector<Student> SortingController::run(char option) {
    // Student Model에서 모든 학생 리스트를 복사
    std::vector<Student> sorted_list = model->getAllStudents();
    
    switch (option) {
    // std::sort (인트로소트) 실행
    // 퀵정렬, 힙정렬, 삽입정렬을 종합한 방법
    case '1': // Sort by Name
        std::sort(sorted_list.begin(), sorted_list.end(),
            [](const Student& a, const Student& b) {
                return a.getName() < b.getName();
            });
        views->displayMessage("Sorting option set to Name.");
        break;

    case '2': // Sort by s-id
        std::sort(sorted_list.begin(), sorted_list.end(),
            [](const Student& a, const Student& b) {
                return a.getStudentID() < b.getStudentID();
            });
        views->displayMessage("Sorting option set to Student ID.");
        break;

    case '3': // Sort by birth
        std::sort(sorted_list.begin(), sorted_list.end(),
            [](const Student& a, const Student& b) {
                return a.getBirthYear() < b.getBirthYear();
            });
        views->displayMessage("Sorting option set to Birth Year.");
        break;

    case '4': // Sort by dept
        std::sort(sorted_list.begin(), sorted_list.end(),
            [](const Student& a, const Student& b) {
                return a.getDepartment() < b.getDepartment();
            });
        views->displayMessage("Sorting option set to Department.");
        break;

    default:
        views->displayMessage("Error: Invalid option passed to controller.");
        return {};
    }
    return sorted_list; // 정렬된 리스트 반환
}