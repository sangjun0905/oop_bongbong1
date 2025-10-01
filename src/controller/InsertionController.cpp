#include <iostream>
#include <string>

#include "../model/StudentList.hpp"
#include "../view/InsertionView.hpp"

class InsertionController
{
private:
    StudentList studentList;
    InsertionView insertionView;

public:
    InsertionController(InsertionView& insertionView, StudentList& studentList);
    ~InsertionController();

    void insert();
};

InsertionController::InsertionController(InsertionView& insertionView, StudentList& studentList)
{
    this->studentList = studentList;
    this->insertionView = insertionView;
}

InsertionController::~InsertionController()
{
}

void InsertionController::insert()
{
    insertionView.display();
    studentList.addStudent(
        insertionView.getName().c_str(),
        insertionView.getStudentID().c_str(),
        insertionView.getBirthYear().c_str(),
        insertionView.getDepartment().c_str(),
        insertionView.getTel().c_str()
    );
}