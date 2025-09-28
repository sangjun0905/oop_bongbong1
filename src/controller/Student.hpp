/*#pragma once
#include <string>

using namespace std;

//임의로 설정함(나중에 없애야함)
struct student {
    char name[16];
    int studentID;
    int birthyear;
    char department[64];
    char tel[24];
};*/

#ifndef STUDENT_HPP 
#define STUDENT_HPP

class Student {
public :   
    char name[16];
    int studentID;
    int birthyear;
    char department[64];
    char tel[24];
    
    std::string getName() const { /* ... */ };
    std::string getStudentID() const { /* ... */ };
    std::string getBirthYear() const { /* ... */ };
    std::string getDepartment() const { /* ... */ };
    std::string getTel() const { /* ... */ };
    std::string getAllStudents();
};

#endif

