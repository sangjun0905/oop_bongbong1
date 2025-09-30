#ifndef INSERTIONVIEW_HPP
#define INSERTIONVIEW_HPP

#include <iostream>
#include <string>

class InsertionView {
public:
    void display();
    std::string getName();
    std::string getStudentID();
    std::string getBirthYear();
    std::string getDepartment();
    std::string getTel();

private:
    int checkName(const std::string& inputName);
    int checkStudentID(const std::string& inputStudentID);
    int checkBirthYear(const std::string& inputBirthYear);
    int checkDepartment(const std::string& inputDepartment);
    int checkTel(const std::string& inputTel);
};

#endif
