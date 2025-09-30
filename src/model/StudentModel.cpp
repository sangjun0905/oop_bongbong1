#include "StudentModel.hpp"
#include <string>
#include <vector>

void StudentModel::addStudent(const Student& new_student){
    studentList.push_back(new_student);
}

void StudentModel::addStudent(const std::string& name, const std::string& studentID, const std::string& birthYear, const std::string& department, const std::string& tel)
{
    Student new_student(
        name.c_str(),
        std::stoi(studentID),
        tel.c_str(),
        std::stoi(birthYear),
        department.c_str()
    );
    studentList.push_back(new_student);
}

const std::vector<Student>& StudentModel::getAllStudents(){
    return studentList;
}
