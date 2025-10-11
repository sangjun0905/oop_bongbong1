#include "InsertionView.hpp"

#include <iostream>
#include <string>

namespace view::insertion {

std::string InsertionNameView::display() {
    
    output = "--- Add New Student ---\n"
            "Name: ";
    std::cout << output; 

};

std::string InsertionStudentIDView::display() {
    
    output = "Student ID: ";
    std::cout << output; 

};

std::string InsertionBirthYearView::display() {
    
    output = "Birth Year: ";
    std::cout << output;
};

std::string InsertionDepartmentView::display() {
    
    output = "Department: ";
    std::cout << output;
};

std::string InsertionTelView::display() {
    
    output = "Telephone: ";
    std::cout << output;
};

}