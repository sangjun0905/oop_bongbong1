#pragma once
#include "Controller.hpp"
#include "../view/InsertionView.hpp"
#include "InsertionNameController.hpp" // 다음 단계 컨트롤러

class InsertionController : public Controller {
public:
    InsertionView& insertionView;

    InsertionController(StudentList& stuList, InsertionView& iv)
        : Controller(stuList, iv), insertionView(iv) {}

    std::unique_ptr<Controller> nextController(char sel) override {
        this->insertionView.display();

        return std::make_unique<InsertionNameController>(
            this->studentList,
            this->insertionView,
            sel
        );
    }
};

