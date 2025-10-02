#include <iostream>
#include <string>
#include <vector>

#include "SearchController.hpp"
#include "../model/StudentList.hpp"

SearchController::SearchController(SearchView& sView) : searchView(sView) {}

void SearchController::search(StudentList& list)
{
    char option;
    std::string keyword;
    searchView.display();
    option = searchView.getSearchOption();
    keyword = searchView.getSearchKeyword(option);
}

StudentList SearchController::searchStudent(StudentList& list, char option, std::string keyword)
{
    std::vector<Student> students = list.getAllStudents();
    for (int i = 0; i < students.size(); i++)
    {
        
    }
}