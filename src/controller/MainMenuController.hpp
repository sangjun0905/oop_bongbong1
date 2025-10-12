#pragma once

#include <memory>
#include <string>

#include "Controller.hpp"
#include "../view/MainMenuView.hpp"
#include "../view/SearchSelectionView.hpp"

class SortSelectionController; // forward declare to avoid include cycle

class MainMenuController : public Controller { 
public:
    explicit MainMenuController(StudentList& list) : Controller(list) {}

    std::string display() override { return view_.display(); }

    std::unique_ptr<Controller> nextController(std::string input) override;

private:
    MainMenuView view_{};
    SearchSelectionView searchSelView_{}; // placeholder for future search chain
};
