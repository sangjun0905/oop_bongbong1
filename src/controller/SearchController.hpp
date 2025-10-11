#pragma once

#include "../view/SearchView.hpp"
#include "../model/StudentList.hpp"
#include "Controller.hpp"
#include <memory>
#include <string>

class SearchByNameController;
class SearchByNameResultController;
class SearchByStudentIdController;
class SearchByStudentIdResultController;
class SearchByAdmissionYearController;
class SearchByAdmissionYearResultController;
class SearchByBirthYearController;
class SearchByBirthYearResultController;
class SearchByDepartmentController;
class SearchByDepartmentResultController;
class SearchAllResultController;

class SearchSelectionController : public Controller {
public:
    SearchSelectionController(StudentList& list, SearchSelectionView& sv) : studentList(list), view(sv) {}

    std::unique_ptr<Controller> nextController(std::string input) override {
        if (input == "1") return std::make_unique<class SearchNameController>(studentList, SearchNameView());
        if (input == "2") return std::make_unique<class SearchStudentIdController>(studentList, SearchStudentIdView());
        if (input == "3") return std::make_unique<class SearchAdmissionYearController>(studentList, SearchAdmissionYearView());
        if (input == "4") return std::make_unique<class SearchBirthYearController>(studentList, SearchBirthYearView());
        if (input == "5") return std::make_unique<class SearchDepartmentController>(studentList, SearchDepartmentView());
        if (input == "6") return std::make_unique<class SearchResultController>(studentList, SearchResultView());
        return std::make_unique<class this>(studentList, SearchSelectionView());
    }
private:
    SearchSelectionView& view;
};

class SearchNameController : public Controller {
public:
    SearchNameController(StudentList& list, SearchNameView& sv) : studentList(list), view(sv) {}
    std::unique_ptr<Controller> nextController(std::string input) override {
        
        return std::make_unique<class SearchResultView>(studentList, SearchResultView());
    }
private:
    SearchNameView& view;
};
class SearchStudentIdController : public Controller {
public:
    SearchStudentIdController(StudentList& list, SearchStudentIdView& sv) : studentList(list), view(sv) {}
    std::unique_ptr<Controller> nextController(std::string input) override {
        
        return std::make_unique<class SearchResultView>(studentList, SearchResultView());
    }
private:
    SearchStudentIdView& view;
};
class SearchAdmissionYearController : public Controller {
public:
    SearchAdmissionYearController(StudentList& list, SearchAdmissionYearView& sv) : studentList(list), view(sv) {}
    std::unique_ptr<Controller> nextController(std::string input) override {
        
        return std::make_unique<class SearchResultView>(studentList, SearchResultView());
    }
private:
    SearchAdmissionYearView& view;
};
class SearchBirthYearController : public Controller {
public:
    SearchBirthYearController(StudentList& list, SearchBirthYearView& sv) : studentList(list), view(sv) {}
    std::unique_ptr<Controller> nextController(std::string input) override {
        
        return std::make_unique<class SearchResultView>(studentList, SearchResultView());
    }
private:
    SearchBirthYearView& view;
};
class SearchDepartmentController : public Controller {
public:
    SearchDepartmentController(StudentList& list, SearchDepartmentView& sv) : studentList(list), view(sv) {}
    std::unique_ptr<Controller> nextController(std::string input) override {
        
        return std::make_unique<class SearchResultView>(studentList, SearchResultView());
    }
private:
    SearchDepartmentView& view;
};
class SearchResultController : public Controller {
public:
    SearchResultController(StudentList& list, SearchResultView& sv) : Controller(list), view(sv) {}
    std::string display() {
        return view.display(stuList);
    }
    std::unique_ptr<Controller> nextController(std::string) override {
        return std::make_unique<class MainMenuController>(studentList, MainMenuView());
    }
private:
    SearchResultView& view;
};
