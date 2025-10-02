#pragma once

#include "../view/SearchView.hpp"
#include "../model/StudentList.hpp"

class SearchController
{
private:
    SearchView searchView;
    StudentList* searchStudent(StudentList& list, char option, std::string& keyword);

public:
    SearchController(SearchView& sView);
    void search(StudentList& list);
};
