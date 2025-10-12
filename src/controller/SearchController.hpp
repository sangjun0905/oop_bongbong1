#pragma once

#include <functional>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>

#include "Controller.hpp"
#include "../view/SearchSelectionView.hpp"

class SearchResultController;
class SearchNameController;
class SearchStudentIdController;
class SearchAdmissionYearController;
class SearchBirthYearController;
class SearchDepartmentController;

namespace search_detail {
inline StudentList filterStudents(
    StudentList& source,
    const std::function<bool(const Student&)>& predicate) {
    StudentList results;
    for (int i = 0; i < source.size(); ++i) {
        Student candidate = source.getStudent(i);
        if (predicate(candidate)) {
            try {
                results.addStudent(candidate);
            } catch (const std::runtime_error&) {
                // StudentList rejects duplicate IDs; skip duplicates silently.
            }
        }
    }
    return results;
}
} // namespace search_detail

class SearchSelectionController : public Controller {
public:
    explicit SearchSelectionController(StudentList& list) : Controller(list) {}

    std::string display() override { return selectionView_.display(); }

    std::unique_ptr<Controller> nextController(std::string input) override;

private:
    SearchSelectionView selectionView_{};
};

class SearchResultController : public Controller {
public:
    SearchResultController(StudentList& list, StudentList results)
        : Controller(list), resultView_(std::move(results)) {}

    std::string display() override { return resultView_.display(); }

    std::unique_ptr<Controller> nextController(std::string /*input*/) override {
        return std::make_unique<MainMenuController>(studentList);
    }

private:
    SearchResultView resultView_;
};

class SearchNameController : public Controller {
public:
    explicit SearchNameController(StudentList& list) : Controller(list) {}

    std::string display() override { return nameView_.display(); }

    std::unique_ptr<Controller> nextController(std::string input) override {
        auto results = search_detail::filterStudents(
            studentList, [&](const Student& student) {
                return std::string(student.getName()).find(input) != std::string::npos;
            });
        return std::make_unique<SearchResultController>(studentList, std::move(results));
    }

private:
    SearchNameView nameView_{};
};

class SearchStudentIdController : public Controller {
public:
    explicit SearchStudentIdController(StudentList& list) : Controller(list) {}

    std::string display() override { return idView_.display(); }

    std::unique_ptr<Controller> nextController(std::string input) override {
        auto results = search_detail::filterStudents(
            studentList, [&](const Student& student) {
                return std::string(student.getStudentId()).find(input) != std::string::npos;
            });
        return std::make_unique<SearchResultController>(studentList, std::move(results));
    }

private:
    SearchStudentIDView idView_{};
};

class SearchAdmissionYearController : public Controller {
public:
    explicit SearchAdmissionYearController(StudentList& list) : Controller(list) {}

    std::string display() override { return admissionYearView_.display(); }

    std::unique_ptr<Controller> nextController(std::string input) override {
        auto results = search_detail::filterStudents(
            studentList, [&](const Student& student) {
                return std::string(student.getAdmissionYear()).find(input) != std::string::npos;
            });
        return std::make_unique<SearchResultController>(studentList, std::move(results));
    }

private:
    SearchAdmissionYearView admissionYearView_{};
};

class SearchBirthYearController : public Controller {
public:
    explicit SearchBirthYearController(StudentList& list) : Controller(list) {}

    std::string display() override { return birthYearView_.display(); }

    std::unique_ptr<Controller> nextController(std::string input) override {
        auto results = search_detail::filterStudents(
            studentList, [&](const Student& student) {
                return std::to_string(student.getBirthYear()).find(input) != std::string::npos;
            });
        return std::make_unique<SearchResultController>(studentList, std::move(results));
    }

private:
    SearchBirthYearView birthYearView_{};
};

class SearchDepartmentController : public Controller {
public:
    explicit SearchDepartmentController(StudentList& list) : Controller(list) {}

    std::string display() override { return departmentView_.display(); }

    std::unique_ptr<Controller> nextController(std::string input) override {
        auto results = search_detail::filterStudents(
            studentList, [&](const Student& student) {
                return std::string(student.getDepartment()).find(input) != std::string::npos;
            });
        return std::make_unique<SearchResultController>(studentList, std::move(results));
    }

private:
    SearchDepartmentView departmentView_{};
};

inline std::unique_ptr<Controller> SearchSelectionController::nextController(std::string input) {
    if (input == "1") return std::make_unique<SearchNameController>(studentList);
    if (input == "2") return std::make_unique<SearchStudentIdController>(studentList);
    if (input == "3") return std::make_unique<SearchAdmissionYearController>(studentList);
    if (input == "4") return std::make_unique<SearchBirthYearController>(studentList);
    if (input == "5") return std::make_unique<SearchDepartmentController>(studentList);
    if (input == "6") {
        StudentList all = studentList;
        return std::make_unique<SearchResultController>(studentList, std::move(all));
    }
    return std::make_unique<SearchSelectionController>(studentList);
}
