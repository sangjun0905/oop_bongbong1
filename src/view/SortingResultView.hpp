#ifndef SORTINGRESULTVIEW_HPP
#define SORTINGRESULTVIEW_HPP

#include "Student.hpp"
#include "StudentModel.hpp"

class SortingResultView {
public:
    void displaySearchResults(const std::vector<Student>& results); 
};

#endif