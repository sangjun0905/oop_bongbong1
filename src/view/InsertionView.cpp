#include <iostream>
#include <cstdlib>

class InsertionView {
public:
    void display() {
        std::cout << "Insert Student Information" << std::endl;
    }
    
    char* getName() {
        char inputName[16];
        do {
            std::cout << "Name: ";
            std::cin >> inputName;
        } while (checkName(inputName));
        return inputName;
    }
    int getStudentID() {
        char inputStudentID[16];
        do {
            std::cout << "StudentID: ";
            std::cin >> inputStudentID;
        } while (checkName(inputStudentID));
        return std::atoi(inputStudentID);
    }
    int getBirthYear() {
        char inputBirthYear[16];
        do {
            std::cout << "BirthYear: ";
            std::cin >> inputBirthYear;
        } while (checkBirthYear(inputBirthYear));
        return std::atoi(inputBirthYear);
    }
    char* getDepartment() {
        char inputDepartment[64];
        do {
            std::cout << "Department: ";
            std::cin >> inputDepartment;
        } while (checkDepartment(inputDepartment));
        return inputDepartment;
    }
    char* getTel() {
        char inputTel[24];
        do {
            std::cout << "Tel: ";
            std::cin >> inputTel;
        } while (checkTel(inputTel));
        return inputTel;
    }
    
    int checkName(char* inputName) {
        return 0;
    }
    int checkStudentID(char* inputStudentID) {
        return 0;
    }
    int checkBirthYear(char* inputBirthYear) {
        return 0;
    }
    int checkDepartment(char* inputDepartment) {
        return 0;
    }
    int checkTel(char* inputTel) {
        return 0;
    }
};