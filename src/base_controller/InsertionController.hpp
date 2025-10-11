#pragma once
#include "Controller.hpp"
#include "../view/InsertionView.hpp"
#include "InsertionNameController.hpp" // 다음 단계 컨트롤러

class InsertionController : public Controller {
public:
    InsertionView& insertionView;

    InsertionController(StudentList& stuList, InsertionView& iv);

    std::unique_ptr<Controller> nextController(char sel) override;
};
