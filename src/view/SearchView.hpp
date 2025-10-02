#pragma once
#include "../model/StudentList.hpp"
#include <string>

class SearchView
{
private:
    char check_option(std::string& input);
    char check_keyword(char option, std::string& input);
public:
    void display();
    char getSearchOption();
    std::string getSearchKeyword(char option);
    void printResult(StudentList searchResult);
};
