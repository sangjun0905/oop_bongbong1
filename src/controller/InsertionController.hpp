#pragma once

#include <memory>
#include <string>
#include <stdexcept>
#include <iostream>

#include "Controller.hpp"
#include "../model/StudentList.hpp"
#include "../view/InsertionView.hpp"
#include "MainMenuController.hpp"

// Step 1: Name
class InsertionStudentIDController; // fwd

class InsertionNameController : public Controller {
public:
    // Construct with default internal view
    explicit InsertionNameController(StudentList& list)
        : Controller(list) {}

    // Allow construction with a provided view instance (e.g., InsertionNameView())
    InsertionNameController(StudentList& list, InsertionNameView vw)
        : Controller(list), nameView_(std::move(vw)) {}

    std::string display() override { return nameView_.display(); }

    std::unique_ptr<Controller> nextController(std::string input) override;

private:
    InsertionNameView nameView_{};
};

// Step 2: Student ID
class InsertionBirthYearController; // fwd

class InsertionStudentIDController : public Controller {
public:
    InsertionStudentIDController(StudentList& list, std::string name)
        : Controller(list), name_(std::move(name)) {}

    std::string display() override { return idView_.display(); }

    std::unique_ptr<Controller> nextController(std::string input) override;

private:
    std::string name_;
    InsertionStudentIdView idView_{};
};

// Step 3: Birth Year
class InsertionDepartmentController; // fwd

class InsertionBirthYearController : public Controller {
public:
    InsertionBirthYearController(StudentList& list, std::string name, std::string studentId)
        : Controller(list), name_(std::move(name)), id_(std::move(studentId)) {}

    std::string display() override { return birthView_.display(); }

    std::unique_ptr<Controller> nextController(std::string input) override;

private:
    std::string name_;
    std::string id_;
    InsertionBirthYearView birthView_{};
};

// Step 4: Department
class InsertionTelController; // fwd

class InsertionDepartmentController : public Controller {
public:
    InsertionDepartmentController(StudentList& list, std::string name, std::string studentId, std::string birth)
        : Controller(list), name_(std::move(name)), id_(std::move(studentId)), birth_(std::move(birth)) {}

    std::string display() override { return deptView_.display(); }

    std::unique_ptr<Controller> nextController(std::string input) override;

private:
    std::string name_;
    std::string id_;
    std::string birth_;
    InsertionDepartmentView deptView_{};
};

// Step 5: Tel (finalize insertion)
class InsertionTelController : public Controller {
public:
    InsertionTelController(StudentList& list, std::string name, std::string studentId, std::string birth, std::string dept)
        : Controller(list), name_(std::move(name)), id_(std::move(studentId)), birth_(std::move(birth)), dept_(std::move(dept)) {}

    std::string display() override { return telView_.display(); }

    std::unique_ptr<Controller> nextController(std::string input) override;

private:
    std::string name_;
    std::string id_;
    std::string birth_;
    std::string dept_;
    InsertionTelView telView_{};
};

// Inline implementations for nextController transitions

inline std::unique_ptr<Controller> InsertionNameController::nextController(std::string input) {
    // input is Name
    if (input.empty()) {
        std::cerr << "Student Name cannot be empty" << std::endl;
        return std::make_unique<InsertionNameController>(studentList);
    }
    if (input.length() > 15) {
        std::cout << "Error: Name must be between 1 and 15 characters." << std::endl;
        return std::make_unique<InsertionNameController>(studentList);
    }
    return std::make_unique<InsertionStudentIDController>(studentList, std::move(input));
}

inline std::unique_ptr<Controller> InsertionStudentIDController::nextController(std::string input) {
    if (input.empty()) {
        std::cerr << "Student ID cannot be empty" << std::endl;
        return std::make_unique<InsertionStudentIDController>(studentList, std::move(input));
    }
    if (input.length() != 10) {
        std::cout << "Error: Student ID must be 10 characters." << std::endl;
        return std::make_unique<InsertionStudentIDController>(studentList, std::move(input));
    }
    for (char const &c : input) {
        if (std::isdigit(c) == 0) {
            std::cout << "Error: Student ID must only contain digits." << std::endl;
            return std::make_unique<InsertionStudentIDController>(studentList, std::move(input));
        }
    }
    
    return std::make_unique<InsertionBirthYearController>(studentList, std::move(name_), std::move(input));
}

inline std::unique_ptr<Controller> InsertionBirthYearController::nextController(std::string input) {
    // input is Birth Year (string, e.g., "2001")
    if (input.length() != 4) {
        std::cout << "Error: Birth year must be 4 digits." << std::endl;
        return std::make_unique<InsertionBirthYearController>(studentList, std::move(name_), std::move(input));
    }
    for (char const &c : input) {
        if (std::isdigit(c) == 0) {
            std::cout << "Error: Birth year must only contain digits." << std::endl;
            return std::make_unique<InsertionBirthYearController>(studentList, std::move(name_), std::move(input));
        }
    }
    return std::make_unique<InsertionDepartmentController>(studentList, std::move(name_), std::move(id_), std::move(input));
}

inline std::unique_ptr<Controller> InsertionDepartmentController::nextController(std::string input) {
    // input is Department
    if (input.empty() || input.length() > 23) {
        std::cout << "Error: Department name must be between 1 and 23 characters." << std::endl;
        return std::make_unique<InsertionDepartmentController>(studentList, std::move(name_), std::move(id_), std::move(input));

    }
    return std::make_unique<InsertionTelController>(studentList, std::move(name_), std::move(id_), std::move(birth_), std::move(input));
}

inline std::unique_ptr<Controller> InsertionTelController::nextController(std::string input) {
    // input is Tel; finalize insertion
    if (input.empty() || input.length() > 12) {
        std::cout << "Error: Telephone number must be between 1 and 12 characters." << std::endl;
        return std::make_unique<InsertionTelController>(studentList, std::move(name_), std::move(id_), std::move(birth_), std::move(input));
    }
    try {
        studentList.addStudent(name_, id_, input, birth_, dept_);
    } catch (const std::runtime_error& e) {
        // Duplicate ID or other rule; surface error and stay on this step
        std::cerr << e.what() << std::endl;
        return std::make_unique<InsertionNameController>(studentList);
    }
    return std::make_unique<MainMenuController>(studentList);
}