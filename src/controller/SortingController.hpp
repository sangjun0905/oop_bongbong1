#ifndef SORTINGCONTROLLER_HPP
#define SORTINGCONTROLLER_HPP

#include "Student.hpp"
#include "StudentList.hpp"
#include <vector> // run()의 반환형

class SortingController {
private:
    Display* display;
    StudentModel* model;

public:
    SortingController(Display* display, StudentModel* m);
    std::vector<Student> run(char option);
};

class Display{
public: 
    void displayMessage(const std::string& message);
};

#endif