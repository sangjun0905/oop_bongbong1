#ifndef SORTINGMODULE_HPP
#define SORTINGMODULE_HPP

#include "Student.hpp"
#include <vector> // run()의 반환형

class SortingController {
private:
    Student* model;

public:
    SortingController(Views* v, Student_Model* m);
    std::vector<Student> run(char option);
};

class SortingResultView {
public:
    void displaySearchResults(const std::vector<Student>& results); 
};

class display{
public: 
    void displayMessage(const std::string& message);
};

#endif