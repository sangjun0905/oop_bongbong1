#include "SearchModule.hpp"
#include <iostream>
#include <algorithm> // std::sort 사용
#include <iterator> // std::back_inserter 사용

SearchController::SearchController(Display* d, Student* m)
    : display(d), model(m) {}

std::vector<Student> SearchController::run(char option) {
    std::vector<Student> search_results;
    std::vector<Student> all_students = model->getAllStudents(); 
    // Student에서 getAllStudents() 정의 필요
    // 혹은 전체 학생 vector을 만들어서 유지
    std::string query; // 검색어
    switch (option) {
    case '1': // Search by Name
        display->displayMessage("Name keyword? ");
        std::cin >> query;
        std::copy_if(all_students.begin(), all_students.end(), std::back_inserter(search_results),
            [&query](const Student& s) {
                return s.getName() == query;
            });
        break;

    case '2': // Search by Student ID
        display->displayMessage("Student ID keyword? ");
        std::cin >> query;
        std::copy_if(all_students.begin(), all_students.end(), std::back_inserter(search_results),
            [&query](const Student& s) {
                return s.getStudentID() == query;
            });
        break;

    case '3': // Search by Admission Year
        display->displayMessage("Admission year keyword? ");
        std::cin >> query;
        std::copy_if(all_students.begin(), all_students.end(), std::back_inserter(search_results),
            [&query](const Student& s) {
                return s.getAdmissionYear() == query;
            });
        break;

    case '4': // Search by Birth Year
        display->displayMessage("Birth year keyword? ");
        std::cin >> query;
        std::copy_if(all_students.begin(), all_students.end(), std::back_inserter(search_results),
            [&query](const Student& s) {
                return s.getBirthYear() == query;
            });
        break;

    case '5': // Search by Department
        display->displayMessage("Department name keyword? ");
        std::cin >> query;
        std::copy_if(all_students.begin(), all_students.end(), std::back_inserter(search_results),
            [&query](const Student& s) {
                return s.getDepartment() == query;
            });
        break;

    case '6': // List ALL
        search_results = all_students; // 모든 학생을 결과에 복사
        display->displayMessage("Listing all students.");
        break;
        
    case '7': // Go back to main menu
        display->displayMessage("Returning to main menu.");
        break;

    default:
        display->displayMessage("Error: Invalid option.");          
        return {}; // 빈 벡터 반환
    }
    return search_results;    
} 


