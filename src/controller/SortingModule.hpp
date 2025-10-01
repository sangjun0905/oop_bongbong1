#ifndef SORTINGMODULE_HPP
#define SORTINGMODULE_HPP

#include "Student.hpp"
#include "StudentModel.hpp"
#include <vector> // run()의 반환형

class SortingController {
private:
    Display* display;
    StudentModel* model;

public:
    SortingController(Display* display, StudentModel* m);
    std::vector<Student> run(char option);
};

class SortingResultView {
public:
    void displaySearchResults(const std::vector<Student>& results); 
};

class Display{
public: 
    void displayMessage(const std::string& message);
};

#endif