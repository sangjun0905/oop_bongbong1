#include "Student.hpp"
#include <stdexcept>
#include <sstream>
#include <string>

Student::Student(const std::string& name, const std::string& stdudentId, const std::string& department, const std::string& tel){

    if(name.empty()||studentId.empty()){
        throw std::invalid_argument("Name and Student ID cannot be blank.");
    }

    if()
}