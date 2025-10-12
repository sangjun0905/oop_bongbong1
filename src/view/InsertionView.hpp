#pragma once 

#include "View.hpp"
#include <iostream>
#include <string>

class InsertionNameView : public View{
public:
    std::string display() override {
        output = "--- Add New Student ---\n"
                "Name: ";
        std::cout << output;
        return output; 
    }
};

class InsertionStudentIdView : public View{
public:
    std::string display() override {
        output = "Student ID: ";
        std::cout << output; 
        return output;
    }
};

class InsertionBirthYearView : public View{
public:
    std::string display() override {
        output = "Birth Year: ";
        std::cout << output;
        return output;    
    }
};

class InsertionDepartmentView : public View{
public:
    std::string display() override {
        output = "Department: ";
        std::cout << output;
        return output;
    }
};

class InsertionTelView : public View{
public:
    std::string display() override {
        output = "Telephone: ";
        std::cout << output;
        return output + " Main";
    }
};
