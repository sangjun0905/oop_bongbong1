#include "StudentList.hpp"
#include <vector>
#include <string>
#include <stdexcept>

void StudentList::addStudent(const Student& newStudent){
    if(isIdDuplicated(newStudent)){
        throw std::runtime_error("Error : Already inserted");
    }
    else{
        student_list.push_back(newStudent);
    }
}

void StudentList::addStudent(const std::string& name, const std::string& studentId, const std::string& tel, const std::string& birth, const std::string& department) {
    Student newStudent(name.c_str(), studentId.c_str(), tel.c_str(), std::stoi(birth), department.c_str());
    if(isIdDuplicated(newStudent)){
        throw std::runtime_error("Error : Already inserted");
    }
    else{
        student_list.push_back(newStudent);
    }
}

int StudentList::size() { return student_list.size(); }
Student StudentList::getStudent(int index)
{
    if (index >= student_list.size()) 
        throw "Error: Index out of range";
    else 
        return student_list.at(index);
}

std::vector<Student>& StudentList::getAllStudents() {
    return student_list;
}

bool StudentList::isIdDuplicated(const Student& newStudent){
    for(const auto& student : student_list){
        if(0 == std::strcmp(student.getStudentId() , newStudent.getStudentId())){
            return true;
        }
    }
    return false;

}