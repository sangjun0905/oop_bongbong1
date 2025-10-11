#include "Controller.hpp"

class MainMenuController : public Controller { 
private:
    MainMenuView& view;

public:
    MainMenuController(StudentList& list, MainMenuView& vw) : studentList(list), view(vw) {};

    std::unique_ptr<Controller> nextController(std::string input) override {
        if (input == "1") return std::make_unique<class InsertionNameController>(studentList, InsertionNameView());
        if (input == "2") return std::make_unique<class SearchSelectionController>(studentList, SearchSelectionView());
        if (input == "3") return std::make_unique<class SortSelectionController>(studentList, SortSelecitonView());
        
        return std::make_unique<class this>(studentList, MainMenuView());
    }
}