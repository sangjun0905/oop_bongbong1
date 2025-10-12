#pragma once

#include <memory>
#include <algorithm>
#include <string>

#include "../view/SortSelectionView.hpp" // contains SortSelectView and SortResultView
#include "../view/MainMenuView.hpp"

#include "../model/StudentList.hpp"

#include "Controller.hpp"
#include "MainMenuController.hpp"

class SortByNameController : public Controller {
public:
    explicit SortByNameController(StudentList& list) : Controller(list) {}

    std::string display() override {
        auto& students = studentList.getAllStudents();
        std::sort(students.begin(), students.end(),
                  [](const Student& a, const Student& b) {
                      return std::string(a.getName()) < std::string(b.getName());
                  });
        return resultView_.display();
    }
    std::unique_ptr<Controller> nextController(std::string /*input*/ = "") override {
        // After showing sorted result, go back to main menu
        return std::make_unique<MainMenuController>(studentList);
    }
private:
    SortResultView resultView_{};
};

class SortByStudentIdController : public Controller {
public:
    explicit SortByStudentIdController(StudentList& list) : Controller(list) {}

    std::string display() override {
        auto& students = studentList.getAllStudents();
        std::sort(students.begin(), students.end(),
                  [](const Student& a, const Student& b) {
                      return std::string(a.getStudentId()) < std::string(b.getStudentId());
                  });
        return resultView_.display();
    }
    std::unique_ptr<Controller> nextController(std::string /*input*/ = "") override {
        return std::make_unique<MainMenuController>(studentList);
    }
private:
    SortResultView resultView_{};
};

class SortByBirthController : public Controller {
public:
    explicit SortByBirthController(StudentList& list) : Controller(list) {}

    std::string display() override {
        auto& students = studentList.getAllStudents();
        std::sort(students.begin(), students.end(),
                  [](const Student& a, const Student& b) {
                      return a.getBirthYear() < b.getBirthYear();
                  });
        return resultView_.display();
    }
    std::unique_ptr<Controller> nextController(std::string /*input*/ = "") override {
        return std::make_unique<MainMenuController>(studentList);
    }
private:
    SortResultView resultView_{};
};

class SortByDepartmentController : public Controller {
public:
    explicit SortByDepartmentController(StudentList& list) : Controller(list) {}

    std::string display() override {
        auto& students = studentList.getAllStudents();
        std::sort(students.begin(), students.end(),
                  [](const Student& a, const Student& b) {
                      return std::string(a.getDepartment()) < std::string(b.getDepartment());
                  });
        return resultView_.display();
    }
    std::unique_ptr<Controller> nextController(std::string /*input*/ = "") override {
        return std::make_unique<MainMenuController>(studentList);
    }
private:
    SortResultView resultView_{};
};

class SortSelectionController : public Controller {
public:
    explicit SortSelectionController(StudentList& list) : Controller(list) {}

    std::string display() override { return selectionView_.display(); }

    std::unique_ptr<Controller> nextController(std::string input) override {
        if (input == "1") return std::make_unique<SortByNameController>(studentList);
        if (input == "2") return std::make_unique<SortByStudentIdController>(studentList);
        if (input == "3") return std::make_unique<SortByBirthController>(studentList);
        if (input == "4") return std::make_unique<SortByDepartmentController>(studentList);
        // invalid -> remain in selection
        return std::make_unique<SortSelectionController>(studentList);
    }
private:
    SortSelectView selectionView_{};
};
