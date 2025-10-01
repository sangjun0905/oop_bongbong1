#include <iostream>
#include <string>

#include "InsertionController.hpp"
#include "../model/StudentList.hpp"
#include "../view/InsertionView.hpp"

InsertionController::InsertionController(InsertionView& insertion) : insertionView(insertion)
{
}

InsertionController::~InsertionController()
{
}

StudentList& InsertionController::insert(StudentList& studentList)
{
    insertionView.display();
    studentList.addStudent(
        insertionView.getName().c_str(),
        insertionView.getStudentID().c_str(),
        insertionView.getBirthYear().c_str(),
        insertionView.getDepartment().c_str(),
        insertionView.getTel().c_str()
    );
    return studentList;
}
