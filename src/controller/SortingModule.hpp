#ifndef SORTINGMODULE_HPP
#define SORTINGMODULE_HPP

#include "Views.hpp"
#include "Student_Model.hpp" 
#include "Student.hpp"
#include <vector> // std::vector<Student> run()의 반환형을 위해 필요

class SortingController {
private:
    Views* views;
    Student_Model* model;

public:
    // 1. 생성자 선언: Views와 Student_Model 포인터를 받습니다.
    SortingController(Views* v, Student_Model* m);

    // 2. run() 함수 선언: MainController로부터 정렬 옵션(char)을 받아 정렬된 리스트를 반환합니다.
    std::vector<Student> run(char option);
};

class SortingResultView {
public:
    // 정렬된 학생 리스트를 인자로 받아 화면에 출력하는 함수를 선언
    void displaySearchResults(const std::vector<Student>& results); 
};

#endif