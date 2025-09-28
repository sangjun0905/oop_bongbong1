#include "SortingModule.hpp"
#include <iostream>
#include <algorithm> // std::sort 사용

SortingController::SortingController(Display* d, Student* m)
    : display(d), model(m) {}

std::vector<Student> SortingController::run(char option) {
    std::vector<Student> sorted_list = model->getAllStudents(); 
    // Student애서 getAllStudents() 정의 필요
    switch (option) {
    // std::sort (인트로소트) 실행
    // 퀵정렬, 힙정렬, 삽입정렬을 종합한 방법
    case '1': // Sort by Name
        std::sort(sorted_list.begin(), sorted_list.end(), 
        // begin과 end는 벡터의 처음과 끝을 가리키는 반복자, Student에서 정의 필요
            [](const Student& a, const Student& b) {
                return a.getName() < b.getName();
            });
        display->displayMessage("Sorting option set to Name.");
        break;

    case '2': // Sort by s-id
        std::sort(sorted_list.begin(), sorted_list.end(),
            [](const Student& a, const Student& b) {
                return a.getStudentID() < b.getStudentID();
            });
        display->displayMessage("Sorting option set to Student ID.");
        break;

    case '3': // Sort by birth
        std::sort(sorted_list.begin(), sorted_list.end(),
            [](const Student& a, const Student& b) {
                return a.getBirthYear() < b.getBirthYear();
            });
        display->displayMessage("Sorting option set to Birth Year.");
        break;

    case '4': // Sort by dept
        std::sort(sorted_list.begin(), sorted_list.end(),
            [](const Student& a, const Student& b) {
                return a.getDepartment() < b.getDepartment();
            });
        display->displayMessage("Sorting option set to Department.");
        break;

    case '5': // Go back to main menu
        display->displayMessage("Returning to main menu.");
        break;

    default:
        display->displayMessage("Error: Invalid option.");
        return {};
    }
    return sorted_list; // 정렬된 리스트를 MainVeiw로 반환
}