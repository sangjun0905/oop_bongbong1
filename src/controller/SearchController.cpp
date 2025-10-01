#include "../model/StudentList.hpp"
#include "SearchController.hpp"
#include <iostream>
#include <algorithm> // std::sort 사용
#include <iterator> // std::back_inserter 사용

void SearchController::run(StudentList &studentList){
    char searchOption;
    searchOption = searchView.display();
    if(searchOption == '7') return;
    StudentList searchedList = searching(searchOption, studentList);
    searchResultView.displaySearchResults(searchedList);
};

StudentList SearchController::searching(char searchOption, StudentList studentList){
    return studentList;
};

