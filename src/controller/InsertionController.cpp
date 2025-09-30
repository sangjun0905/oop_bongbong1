#include "InsertionController.hpp"
#include <iostream>

InsertionController::InsertionController(InsertionView& insertionView, StudentModel& studentModel)
 : insertionView(insertionView), studentModel(studentModel)
{
}

InsertionController::~InsertionController()
{
}

void InsertionController::insert()
{
    insertionView.display();
    studentModel.addStudent(
        insertionView.getName(),
        insertionView.getStudentID(),
        insertionView.getBirthYear(),
        insertionView.getDepartment(),
        insertionView.getTel()
    );
}
