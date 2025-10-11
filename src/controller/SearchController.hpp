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

#include "../view/SearchSelectionView.hpp"

#include "Controller.hpp"

class SearchSelectionController : public Controller {
private:
    StudentList& studentList;
    SearchSelectionView& view;
public:
    SearchSelectionController(StudentList& stuList, SearchSelectionView& searchSelView)
        : Controller(stuList, searchSelView) {};
    
    std::unique_ptr<Controller> nextController(std::string input) {
        std::unique_ptr<Controller> cur;
        if (input == "1") {
            cur = std::make_unique<SearchByNameController>(stuList, SearchByNameView());
        }
        else if (input == "2") {
            cur = std::make_unique<SearchByStudentIdController>(stuList, SearchByStudentIdView());
        }
        else if (input == "3") {
            cur = std::make_unique<SearchByAdmissionYearController>(stuList, SearchByAdmissionYearView());
        }
        else if (input == "4") {
            cur = std::make_unique<SearchByBirthYearController>(stuList, SearchByBirthYearView());
        }
        else if (input == "5") {
            cur = std::make_unique<SearchByDepartmentController>(stuList, SearchByDepartmentView());
        }
        else if (input == "6") {
            cur = std::make_unique<SearchAllController>(stuList, SearchAllView());
        }
        else {
            cur = std::make_unique<this>(stuList, SearcSelectionView());
        }
        return cur
    }

}