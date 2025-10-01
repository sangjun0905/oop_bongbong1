#include <iostream>
#include <string.h>

#include "../model/StudentList.hpp"
#include "../view/InsertionView.hpp"

class InsertionController
{
private:
    StudentList studentList;
    InsertionView insertionView;

    char name_in[16];
    char studID_in[10];
    char birthYear_in[4];
    char dept_in[64];
    char tel_in[24];

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
        insertionView.getName(),
        insertionView.getStudentID(),
        insertionView.getBirthYear(),
        insertionView.getDepartment(),
        insertionView.getTel()
    );
}