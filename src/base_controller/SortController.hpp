#pragma once
#include "Controller.hpp"
#include "../view/SortView.hpp"
#include "SortSelectionController.hpp"

class SortController : public Controller {
public:
    SortView& sortView;

    SortController(StudentList& stuList, SortView& sv);

    std::unique_ptr<Controller> nextController(char sel) override;
};
