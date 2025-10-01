#ifndef SEARCHCONTROLLER_HPP
#define SEARCHCONTROLLER_HPP

#include "../model/StudentList.hpp"
#include "../view/SearchView.hpp"
#include "../view/SearchResultView.hpp"
#include <vector> // run()의 반환형

class SearchController {
private:
    SearchView &searchView;
    SearchResultView &searchResultView;

public:
    SearchController(SearchView &searchView, SearchResultView &searchResultView);
    void run(StudentList &studentList);
    StudentList searching(char, StudentList);
};

#endif