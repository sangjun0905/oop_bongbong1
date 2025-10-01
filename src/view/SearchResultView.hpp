#ifndef SEARCHRESULTVIEW_HPP
#define SEARCHRESULTVIEW_HPP

#include "../model/Student.hpp"

class SearchResultView {
public:
    void displaySearchResults(const std::vector<Student>& results);
};

#endif