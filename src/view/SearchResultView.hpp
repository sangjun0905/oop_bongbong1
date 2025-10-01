#ifndef SEARCHRESULTVIEW_HPP
#define SEARCHRESULTVIEW_HPP

#include "../model/StudentList.hpp"
#include "../model/Student.hpp"

class SearchResultView {
public:
    void displaySearchResults(StudentList &studentList);
};

#endif