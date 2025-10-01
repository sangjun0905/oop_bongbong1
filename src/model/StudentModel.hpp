#ifndef STUDENTMODEL_HPP
#define STUDENTMODEL_HPP

#include <vector>
#include <string>
#include "Student.hpp"

class StudentModel {
private:
    std::vector<Student> studentList;

public:
    void addStudent(const Student& new_student);
    void addStudent(const std::string& name, const std::string& studentID, const std::string& birthYear, const std::string& department, const std::string& tel);
    const std::vector<Student>& getAllStudents();
};

#endif