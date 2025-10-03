#include <iostream>
#include <string>
#include <vector>

#include "SearchController.hpp"
#include "../model/StudentList.hpp"

// Public methods
SearchController::SearchController(SearchView& sView) : searchView(sView) {}

void SearchController::search(StudentList& list)
{
    char option;
    std::string keyword;
    StudentList* searchResult;
    searchView.display();
    option = searchView.getSearchOption();

    if (option == '6') // List All
    {
        searchView.printResult(list);
        return;
    } 

    keyword = searchView.getSearchKeyword(option);
    searchResult = searchStudent(list, option, keyword);
    // sort searchResult by sorting option
    searchView.printResult(*searchResult);
    delete searchResult;
}

// Private methods
StudentList* SearchController::searchStudent(StudentList& list, char option, std::string& keyword)
{
    StudentList* searchResult = new StudentList();
    std::string data;

    switch(option){
    case '1':
        for (int i = 0; i < list.size(); i++)
        {
            data = list.getStudent(i).getName();
            if (data.find(keyword) != std::string::npos){
                try{
                searchResult->addStudent(list.getStudent(i));
                }catch (const std::runtime_error& e) {
                    std::cerr << e.what() << std::endl;
                }   
            }
        }
        break;
    case '2':
        for (int i = 0; i < list.size(); i++)
        {
            data = list.getStudent(i).getStudentId();
            if (data.find(keyword) != std::string::npos){
                try{
                searchResult->addStudent(list.getStudent(i));
                }catch (const std::runtime_error& e) {
                    std::cerr << e.what() << std::endl;
                }   
            }
        }
        break;
    case '3':
        for (int i = 0; i < list.size(); i++)
        {
            data = list.getStudent(i).getAdmissionYear();
            if (data.find(keyword) != std::string::npos){
            try{
                searchResult->addStudent(list.getStudent(i));
                }catch (const std::runtime_error& e) {
                    std::cerr << e.what() << std::endl;
                }   
            }
        }
        break;
    case '4':
        for (int i = 0; i < list.size(); i++)
        {
            data = list.getStudent(i).getBirthYear();
            if (data.find(keyword) != std::string::npos){
                try{
                searchResult->addStudent(list.getStudent(i));
                }catch (const std::runtime_error& e) {
                std::cerr << e.what() << std::endl;
                }   
            }
        }
        break;
    case '5':
        for (int i = 0; i < list.size(); i++)
        {
            data = list.getStudent(i).getDepartment();
            if (data.find(keyword) != std::string::npos){
                try{
                searchResult->addStudent(list.getStudent(i));
                }catch (const std::runtime_error& e) {
                std::cerr << e.what() << std::endl;
                }   
            }
        }
        break;
    default:
        break;
    }
    return searchResult;
}