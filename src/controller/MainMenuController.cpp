#include "MainMenuController.hpp"
#include "InsertionController.hpp"
#include "SearchController.hpp"
#include "SortController.hpp"

std::unique_ptr<Controller> MainMenuController::nextController(std::string input) {
    if (input == "1") return std::make_unique<InsertionNameController>(studentList);
    if (input == "2") return std::make_unique<SearchSelectionController>(studentList);
    if (input == "3") return std::make_unique<SortSelectionController>(studentList);
    if (input == "4") return nullptr; // exit
    return std::make_unique<MainMenuController>(studentList); // retry on invalid
}
