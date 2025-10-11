#include "SearchSelectionView.hpp"

#include <iostream>
#include <string>
#include <iomanip>

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
    return "PROMPT:SEARCH_MENU(1..6)";
}

std::string SearchNameView::display() {
    output = "Name Keyword: ";
    std::cout << output;
    return "PROMPT:SEARCH_KEYWORD:NAME";
};

std::string SearchStudentIDView::display() {
    output = "Student ID Keyword: ";
    std::cout << output;
    return "PROMPT:SEARCH_KEYWORD:STUDENT_ID";
};

std::string SearchAdmissionYearView::display() {
    output = "Admission Year Keyword: ";
    std::cout << output;
    return "PROMPT:SEARCH_KEYWORD:ADMISSION_YEAR";
};

std::string SearchBirthYearView::display() {
    output = "Birth Year Keyword: ";
    std::cout << output;
    return "PROMPT:SEARCH_KEYWORD:BIRTH_YEAR";
};

std::string SearchDepartmentView::display() {
    output = "Department Keyword: ";
    std::cout << output;
    return "PROMPT:SEARCH_KEYWORD:DEPARTMENT";
};

SearchResultView SearchResultView::searchResultView(StudentList& list) {
    return searchResultView(list);
};

std::string SearchResultView::display(StudentList& list) {
    std::cout << "Result: " << std::endl;

    if (list.size() == 0)
    {
        std::cout << "NO RESULTS FOUND" << "\n\n";
        return "RESULT:SEARCH:EMPTY";
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
    return std::string("RESULT:SEARCH:COUNT=") + std::to_string(list.size());
};
