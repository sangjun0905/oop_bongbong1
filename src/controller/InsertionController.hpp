#pragma once

#include "../model/StudentList.hpp"
#include "../view/InsertionNameView.hpp"

#include "Controller.hpp"

class InsertionNameController : public Controller {
private:
    StudentList& studentList;
    InsertionNameView& view;
public:
    InsertionNameController(StudentList& stuList, InsertionNameView& insertNameView)
        : studentList(stuList), view(insertNameView) {};

    std::unique_ptr<Controller> nextController(std::string input) {
        studentList.addStudent(name만 있는 학생)

        return std::make_unique<class InsertionStudentIdController>(studentList, InsertionStudentIdView());
    }
}

... 

class InsertionTelController : public Controller {
private:
    StudentList& studentList;
    InsertionTelView& view;
public:
    InsertionTelController(StudentList& stuList, InsertionTelView& insertTelView)
        : studentList(stuList), view(insertTelView) {};

    std::unique_ptr<Controller> nextController(std::string input) {
        studentList.addStudent(마지막 학생에 Tel 추가)

        return std::make_unique<class MainMenuController>(studentList, MainMenuView());
    }
}