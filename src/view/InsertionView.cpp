#include <iostream>

class InsertionView {
private:
    char inputName[16];
    char inputStudentID[16];
    char inputBirthYear[16];
    char inputDepartment[64];
    char inputTel[24];

public:
    char* getName() { return inputName; }
    char* getStudentID() { return inputStudentID; }
    char* getBirthYear() { return inputBirthYear; }
    char* getDepartment() { return inputDepartment; }
    char* getTel() { return inputTel; }

    char* setName() {
        do {
            std::cout << "Name: ";
            std::cin >> inputName;
        } while (checkName(inputName));
        return inputName;
    }
    char* setStudentID() {    
        do {
            std::cout << "StudentID: ";
            std::cin >> inputStudentID;
        } while (checkName(inputStudentID));
        return inputStudentID;
    }
    char* setBirthYear() {    
        do {
            std::cout << "BirthYear: ";
            std::cin >> inputBirthYear;
        } while (checkBirthYear(inputBirthYear));
        return inputBirthYear;
    }
    char* setDepartment() {
        do {
            std::cout << "Department: ";
            std::cin >> inputDepartment;
        } while (checkDepartment(inputDepartment));
        return inputDepartment;
    }
    char* setTel() {
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

    void display() {
        setName();
        setStudentID();
        setBirthYear();
        setDepartment();
        setTel();
    }
};