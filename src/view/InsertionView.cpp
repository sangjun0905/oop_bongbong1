#include "InsertionView.hpp"

#include <iostream>
#include <string>

std::string InsertionNameView::display() {
    
    output = "--- Add New Student ---\n"
            "Name: ";
    std::cout << output;
    return "PROMPT:INSERT_NAME"; 

};

std::string InsertionStudentIDView::display() {
    
    output = "Student ID: ";
    std::cout << output; 
    return "PROMPT:INSERT_STUDENT_ID(10_DIGITS)";

};

std::string InsertionBirthYearView::display() {
    
    output = "Birth Year: ";
    std::cout << output;
    return "PROMPT:INSERT_BIRTH_YEAR(YYYY)";
};

std::string InsertionDepartmentView::display() {
    
    output = "Department: ";
    std::cout << output;
    return "PROMPT:INSERT_DEPARTMENT";
};

std::string InsertionTelView::display() {
    
    output = "Telephone: ";
    std::cout << output;
    return "PROMPT:INSERT_TEL";
};
