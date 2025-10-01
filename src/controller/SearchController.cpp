#include "../model/Student.hpp"
#include <iostream>
#include <algorithm> // std::sort 사용
#include <iterator> // std::back_inserter 사용

SearchController::run(StudentList &studentList){
    char searchOption;
    searchOption = searchView.display();
    if(searchOption == '7') return;
    
};