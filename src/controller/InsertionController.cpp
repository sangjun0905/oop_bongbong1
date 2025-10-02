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
    std::string name = insertionView.getName();
    std::string id = insertionView.getStudentID();
    std::string birth = insertionView.getBirthYear();
    std::string dept = insertionView.getDepartment();
    std::string tel = insertionView.getTel();
    try{
    studentList.addStudent(
        name, id, tel, birth, dept
    );
    }catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }   
    return studentList;
}
