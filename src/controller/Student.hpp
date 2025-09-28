#ifndef STUDENT_HPP // 임시
#define STUDENT_HPP // 임시
//#pragma once // 임시
//#include <string> // 임시
// using namespace std; // 임시

//임의로 설정함(나중에 없애야함)
/*struct student {
    char name[16];
    int studentID;
    int birthyear;
    char department[64];
    char tel[24];
};*/

class Student { // 임시
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

#endif // 임시