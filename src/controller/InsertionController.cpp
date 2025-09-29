#include <iostream>
#include <string.h>

#include "../model/StudentModel.cpp"

#include "../view/InsertionView.cpp"

class InsertionController
{
private:
    StudentModel* studentModel;
    InsertionView* insertionView;

    char name_in[16];
    char studID_in[10];
    char birthYear_in[4];
    char dept_in[64];
    char tel_in[24];

public:
    InsertionController(InsertionView* insertionView, StudentModel* studentModel);
    ~InsertionController();

    void insert();
};

InsertionController::InsertionController(InsertionView* insertionView, StudentModel* studentModel)
{
    this->studentModel = studentModel;
    this->insertionView = insertionView;
}

InsertionController::~InsertionController()
{
}

void InsertionController::insert()
{
    insertionView->display();
    studentModel->addStudent(
        insertionView->getName(),
        insertionView->getStudentID(),
        insertionView->getBirthYear(),
        insertionView->getDepartment(),
        insertionView->getTel()
    );
}