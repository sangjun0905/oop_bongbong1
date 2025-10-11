#include "SearchSelectionView.hpp"

#include <iostream>
#include <string>
#include <iomanip>

namespace view::search {

std::string SearchSelectionView::display() {
        
    output = "--- Search ---\n"
            "1. Search by Name\n"
            "2. Search by Student ID\n"
            "3. Search by Admission Year\n"
            "4. Search by Birth Year\n"
            "5. Search by Department\n"
            "6. List All\n"
            "> ";

    std::cout << output;
}

std::string SearchNameView::display() {
    output = "Name Keyword: ";
    std::cout << output;
};

std::string SearchStudentIDView::display() {
    output = "Student ID Keyword: ";
    std::cout << output;
};

std::string SearchAdmissionYearView::display() {
    output = "Admission Year Keyword: ";
    std::cout << output;
};

std::string SearchBirthYearView::display() {
    output = "Birth Year Keyword: ";
    std::cout << output;
};

std::string SearchDepartmentView::display() {
    output = "Department Keyword: ";
    std::cout << output;
};

std::string SearchErrorView::display() {
    output = "NO RESULTS FOUND";
    std::cout << output << std::endl;
};

std::string SearchResultView::display(StudentList list) {
    if (list.size() == 0)
    {
        std::cout << "NO RESULTS FOUND" << "\n\n";
        return;
    }

    std::cout << std::left << std::setw(15) << "Name" 
        << std::setw(12) << "StudentID"
        << std::setw(23) << "Department"
        << std::setw(12) << "Birth Year"
        << std::setw(12) << "Tel" << std::endl;
    
    for (int i = 0; i < 75; i++)
        std::cout << "-";
    
    std::cout << "\n";

    for (int i = 0; i < list.size(); i++)
    {
        Student student = (list.getStudent(i));
        std::cout << std::left << std::setw(15) << student.getName() 
            << std::setw(12) << student.getStudentId()
            << std::setw(23) << student.getDepartment()
            << std::setw(12) << student.getBirthYear()
            << std::setw(12) << student.getTel() << std::endl;    
    }
    std::cout << "\n";
};

}
