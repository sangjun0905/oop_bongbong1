#pragma once

#include "View.hpp"
#include "../model/StudentList.hpp"
#include <iostream>
#include <string>
#include <iomanip>

class SearchSelectionView : public View { 
public :
    std::string display() override {
    output = "--- Search ---\n"
            "1. Search by Name\n"
            "2. Search by Student ID\n"
            "3. Search by Admission Year\n"
            "4. Search by Birth Year\n"
            "5. Search by Department\n"
            "6. List All\n"
            "> ";

    std::cout << output;
    return output;
    }
};

class SearchNameView : public View { 
public :
    std::string display() override {
        output = "Name Keyword: ";
        std::cout << output;
        return output;    
    }
};

class SearchStudentIDView : public View { 
public :
    std::string display() override {
        output = "Student ID Keyword: ";
        std::cout << output;
        return output;
    }

};

class SearchAdmissionYearView : public View {
public:
    std::string display() override {
        output = "Admission Year Keyword: ";
        std::cout << output;
        return output;
    }
};

class SearchBirthYearView : public View { 
public :
    std::string display() override {
        output = "Birth Year Keyword: ";
        std::cout << output;
        return output;
    }
};

class SearchDepartmentView : public View { 
public :
    std::string display() override {
        output = "Department Keyword: ";
        std::cout << output;
        return output;
    }
};

class SearchResultView : public View {
private :
    StudentList list;
public :
    SearchResultView(StudentList ls) : list(ls) {};
    std::string display() {
        if (list.size() == 0)
        {
            output = "NO RESULTS FOUND";
            std::cout << output << "\n\n";
            return output + " Main";
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

        output = "Search completed";
        std::cout << output << "\n\n";
        return output + " Main";    
    }
};