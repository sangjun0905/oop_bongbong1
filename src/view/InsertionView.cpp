#include "InsertionView.hpp"

#include <iostream>
#include <string>

std::string InsertionNameView::display() {
    
    output = "--- Add New Student ---\n"
            "Name: ";
    std::cout << output;
    return output; 

};

std::string InsertionStudentIDView::display() {
    
    output = "Student ID: ";
    std::cout << output; 
    return output;

};

std::string InsertionBirthYearView::display() {
    
    output = "Birth Year: ";
    std::cout << output;
    return output;
};

std::string InsertionDepartmentView::display() {
    
    output = "Department: ";
    std::cout << output;
    return output;
};

std::string InsertionTelView::display() {
    
    output = "Telephone: ";
    std::cout << output;
    return output;
};
