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
    std::string name = insertionView.getName();
    std::string id = insertionView.getStudentID();
    std::string birth = insertionView.getBirthYear();
    std::string dept = insertionView.getDepartment();
    std::string tel = insertionView.getTel();
    studentList.addStudent(
        name, id, tel, birth, dept
    );
}
