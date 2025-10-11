#pragma once

#include "../model/StudentList.hpp"
#include "../view/InsertionNameView.hpp"

#include "Controller.hpp"

class InsertionController
{
private:
    InsertionView& insertionView;

public:
    InsertionController(InsertionView& insertionView);
    ~InsertionController();

    StudentList& insert(StudentList& studentList);
};

class InsertionNameController : public Controller {
private:
    StudentList& studentList;
    InsertionNameView& view;
    std::string input;
public:
    InsertionNameController(StudentList& stuList, InsertionNameView& insertNameView)
        : Controller(stuList, insertNameView) {};

    void display() {

    }

    std::unique_ptr<Controller> nextController(std::string input) {
        if (check_name) ()
        std::u
    }
}