#include "InsertionView.hpp"
#include <iostream>
#include <string>
#include <limits>

// Private validation methods
int UserInsertionView::checkName(const std::string& inputName) {
    if (inputName.empty() || inputName.length() > 15) {
        std::cout << "Error: Name must be between 1 and 15 characters." << std::endl;
        return 1;
    }
    return 0;
}

int InsertionView::checkStudentID(const std::string& inputStudentID) {
    if (inputStudentID.empty() || inputStudentID.length() > 10) {
        std::cout << "Error: Student ID must be between 1 and 10 characters." << std::endl;
        return 1;
    }
    for (char const &c : inputStudentID) {
        if (std::isdigit(c) == 0) {
            std::cout << "Error: Student ID must only contain digits." << std::endl;
            return 1;
        }
    }
    return 0;
}

int InsertionView::checkBirthYear(const std::string& inputBirthYear) {
    if (inputBirthYear.length() != 4) {
        std::cout << "Error: Birth year must be 4 digits." << std::endl;
        return 1;
    }
    for (char const &c : inputBirthYear) {
        if (std::isdigit(c) == 0) {
            std::cout << "Error: Birth year must only contain digits." << std::endl;
            return 1;
        }
    }
    return 0;
}

int InsertionView::checkDepartment(const std::string& inputDepartment) {
    if (inputDepartment.empty() || inputDepartment.length() > 23) {
        std::cout << "Error: Department name must be between 1 and 23 characters." << std::endl;
        return 1;
    }
    return 0;
}

int InsertionView::checkTel(const std::string& inputTel) {
    if (inputTel.empty() || inputTel.length() > 12) {
        std::cout << "Error: Telephone number must be between 1 and 12 characters." << std::endl;
        return 1;
    }
    return 0;
}


// Public methods
void UserInsertionView::display() {
    ~~

    std::cout << "--- Add New Student ---" << std::endl;
}

std::string InsertionView::getName() {
    std::string input;
    do {
        std::cout << "Name: ";
        // Clear the input buffer before using getline
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, input);
    } while (checkName(input));
    return input;
}

std::string InsertionView::getStudentID() {
    std::string input;
    do {
        std::cout << "Student ID: ";
        std::getline(std::cin, input);
    } while (checkStudentID(input));
    return input;
}

std::string InsertionView::getBirthYear() {
    std::string input;
    do {
        std::cout << "Birth Year: ";
        std::getline(std::cin, input);
    } while (checkBirthYear(input));
    return input;
}

std::string InsertionView::getDepartment() {
    std::string input;
    do {
        std::cout << "Department: ";
        std::getline(std::cin, input);
    } while (checkDepartment(input));
    return input;
}

std::string InsertionView::getTel() {
    std::string input;
    do {
        std::cout << "Telephone: ";
        std::getline(std::cin, input);
    } while (checkTel(input));
    return input;
}
