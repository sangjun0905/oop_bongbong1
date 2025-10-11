#pragma once

#include <memory>
#include <string>
#include <stdexcept>
#include <iostream>

#include "Controller.hpp"
#include "../model/StudentList.hpp"
#include "../view/InsertionView.hpp"

// Step 1: Name
class InsertionStudentIDController; // fwd

class InsertionNameController : public Controller {
public:
    explicit InsertionNameController(StudentList& list, InsertionNameView& view)
        : stdentList(list),  {}

    std::unique_ptr<Controller> nextController(std::string input) override;

private:
    InsertionNameView view;
};

// Step 2: Student ID
class InsertionBirthYearController; // fwd

class InsertionStudentIDController : public Controller {
public:
    InsertionStudentIDController(StudentList& list, std::string name)
        : Controller(list), name_(std::move(name)) {}

    void display() override { idView_.display(); }

    std::unique_ptr<Controller> nextController(std::string input) override;

private:
    std::string name_;
    InsertionStudentIDView idView_{};
};

// Step 3: Birth Year
class InsertionDepartmentController; // fwd

class InsertionBirthYearController : public Controller {
public:
    InsertionBirthYearController(StudentList& list, std::string name, std::string studentId)
        : Controller(list), name_(std::move(name)), id_(std::move(studentId)) {}

    void display() override { birthView_.display(); }

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

    void display() override { deptView_.display(); }

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

    void display() override { telView_.display(); }

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
    return std::make_unique<InsertionStudentIDController>(studentList, std::move(input));
}

inline std::unique_ptr<Controller> InsertionStudentIDController::nextController(std::string input) {
    // input is Student ID
    return std::make_unique<InsertionBirthYearController>(studentList, std::move(name_), std::move(input));
}

inline std::unique_ptr<Controller> InsertionBirthYearController::nextController(std::string input) {
    // input is Birth Year (string, e.g., "2001")
    return std::make_unique<InsertionDepartmentController>(studentList, std::move(name_), std::move(id_), std::move(input));
}

inline std::unique_ptr<Controller> InsertionDepartmentController::nextController(std::string input) {
    // input is Department
    return std::make_unique<InsertionTelController>(studentList, std::move(name_), std::move(id_), std::move(birth_), std::move(input));
}

inline std::unique_ptr<Controller> InsertionTelController::nextController(std::string input) {
    // input is Tel; finalize insertion
    try {
        studentList.addStudent(name_, id_, input, birth_, dept_);
    } catch (const std::runtime_error& e) {
        // Duplicate ID or other rule; surface error and stay on this step
        // Returning nullptr keeps current controller; caller may re-display and retry
        std::cerr << e.what() << std::endl;
        return nullptr;
    }
    return nullptr; // insertion complete; caller can navigate back to menu
}
