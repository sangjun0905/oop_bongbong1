#include "StudentList.hpp"
#include <vector>
#include <string>

void StudentList::addStudent(const Student& new_student){
    student_list.push_back(new_student);
}

void StudentList::addStudent(const std::string& name, const std::string& studentId, const std::string& tel, const std::string& birth, const std::string& department) {
    Student newStudent(name.c_str(), studentId.c_str(), tel.c_str(), std::stoi(birth), department.c_str());
    student_list.push_back(newStudent);
}

int StudentList::size() { return student_list.size(); }
Student StudentList::getStudent(int index)
{
    if (index >= student_list.size()) 
        return;
    else 
        return student_list.at(index);
}

const std::vector<Student>& StudentList::getAllStudents() const {
    return student_list;
}
