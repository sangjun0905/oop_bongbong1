#include "InsertionView.hpp"

#include <iostream>
#include <string>

namespace view::insertion {

void InsertionNameView::display() {
    
    output = "--- Add New Student ---\n"
            "Name: ";
    std::cout << output; 

};

void InsertionStudentIDView::display() {
    
    output = "Student ID: ";
    std::cout << output; 

};

void InsertionBirthYearView::display() {
    
    output = "Birth Year: ";
    std::cout << output;
};

void InsertionDepartmentView::display() {
    
    output = "Department: ";
    std::cout << output;
};

void InsertionTelView::display() {
    
    output = "Telephone: ";
    std::cout << output;
};

}