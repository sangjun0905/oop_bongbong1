#pragma once
#include "Controller.hpp"
#include "../view/SearchView.hpp"
#include "SearchSelectionController.hpp" // 다음 chain된 Controller

class SearchController : public Controller {
public:
    SearchView& searchView;

    SearchController(StudentList& stuList, SearchView& sv);

    std::unique_ptr<Controller> nextController(char sel) override;
};
