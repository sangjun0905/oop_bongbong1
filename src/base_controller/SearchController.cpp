#pragma once
#include "Controller.hpp"
#include "../view/SearchView.hpp"
#include "SearchMenuController.hpp" // 다음 단계 컨트롤러

class SearchController : public Controller {
public:
    SearchView& searchView;

    SearchController(StudentList& stuList, SearchView& sv)
        : Controller(stuList, sv), searchView(sv) {}

    std::unique_ptr<Controller> nextController(char sel) override {
        this->searchView.display();

        return std::make_unique<SearchMenuController>(
            this->studentList,
            this->searchView,
            sel
        );
    }
};
