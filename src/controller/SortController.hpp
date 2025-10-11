#include <memory>

#include "../view/SortSelView.hpp"
#include "../view/SortResultView.hpp"
#include "../view/MainMenuView.hpp"

#include "../model/StudentList.hpp"

#include "Controller.hpp"

class SortByNameController : Controller {
private:
    StudentList& studentList;
    SortResultView& view;
public:
    SortByNameController(StudentList& stuList, SortResultView& sortResultView)
        : Controller(stuList, sortResultView) {};
    
    void display() {
        // 대충 소트하는 로직
    }
    std::unique_ptr<Controller> nextController(std::string input = "") {
        std::unique_ptr<Controller> cur;
        cur = std::make_unique<MainMenuController>(stuList, MainMenuView());
        return cur;
    }
};

class SortByStudentIdController : Controller {
    SortByStudentIdController(StudentList& stuList, SortResultView& sortResultView)
        : Controller(stuList, sortResultView) {};
    
    void display() {
        // 대충 소트하는 로직
    }
    std::unique_ptr<Controller> nextController(std::string input = "") {
        std::unique_ptr<Controller> cur;
        cur = std::make_unique<MainMenuController>(stuList, MainMenuView());
        return cur;
    }
};

class SortByBirthController : Controller {
    SortByBirthController(StudentList& stuList, SortResultView& sortResultView)
        : Controller(stuList, sortResultView) {};
    
    void display() {
        // 대충 소트하는 로직
    }
    std::unique_ptr<Controller> nextController(std::string input = "") {
        std::unique_ptr<Controller> cur;
        cur = std::make_unique<MainMenuController>(stuList, MainMenuView());
        return cur;
    }
};

class SortByDepartmentController : Controller {
    SortByDepartmentController(StudentList& stuList, SortResultView& sortResultView)
        : Controller(stuList, sortResultView) {};
    
    void display() {
        // 대충 소트하는 로직
    }
    std::unique_ptr<Controller> nextController(std::string input = "") {
        std::unique_ptr<Controller> cur;
        cur = std::make_unique<MainMenuController>(stuList, MainMenuView());
        return cur;
    }
};

class SortSelectionController : public Controller {
private:
    StudentList& studentList;
    SortSelectionView& view;
public:
    SortSelectionController(StudentList& stuList, SortSelectionView& sortSelView)
        : Controller(stuList, sortSelView) {};
    
    std::unique_ptr<Controller> nextController(std::string input) {
        std::unique_ptr<Controller> cur;
        if (input == "1") {
            cur = std::make_unique<SortByNameController>(stuList, SortResultView());    
        }
        else if (input == "2") {
            cur = std::make_unique<SortByStudentIdController>(stuList, SortResultView());    
        }
        else if (input == "3") {
            cur = std::make_unique<SortByBirthController>(stuList, SortResultView());
        }
        else if (input == "4") {
            cur = std::make_unique<SortByDepartmentController>(stuList, SortResultView());    
        }
        else {
            cur = std::make_unique<this>(stuList, SortErrorView());
        }
        return cur;
    };
};