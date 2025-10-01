#ifndef SEARCHMODULE_HPP
#define SEARCHMODULE_HPP

#include "StudentModel.hpp"
#include "Student.hpp"
#include <vector> // run()의 반환형

class SearchController {
private:
    Display* display;
    StudentModel* model;

public:
    SearchController(Display* d, StudentModel* m);
    std::vector<Student> run(char option);
};

class SearchResultView {
public:
    void displaySearchResults(const std::vector<Student>& results); 
};

class Display{
public: 
    void displayMessage(const std::string& message);
};

#endif