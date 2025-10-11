#pragma once
#include "Controller.hpp"
#include "../view/SortView.hpp"
#include "SortSelectionController.hpp" // 다음 단계 컨트롤러

class SortController : public Controller {
public:
    SortView& sortView;

    SortController(StudentList& stuList, SortView& sv)
        : Controller(stuList, sv), sortView(sv) {}

    void display() {
        sortView.display();
    }
    
    std::unique_ptr<Controller> nextController(char sel) override {
        return std::make_unique<SortMenuController>(
            this->studentList, 
            this->sortView, 
            sel);
    }
};
