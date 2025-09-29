#include <iostream>
#include "../view/MainMenuView.cpp"
#include "../view/InsertionView.cpp"

#include "SearchController.cpp"
#include "InsertionController.cpp"
#include "SortingController.cpp"
#include "FileController.hpp"

class MainController {
public:
    void run() {
        MainMenuView menuView;
        InsertionView insertionView;
        FileController fileController("text");

        bool start = true;
        while (start) {
            char userSelect = menuView.display();

            switch (userSelect) {
                case '1': {
                    insertionView.display();
                    InsertionController insertionController(insertionView.getName(), insertionView.getStudentID(),
                                                            insertionView.getBirthYear(), insertionView.getDepartment(), 
                                                            nsertionView.getTel());
                    break;
                }
                case '2':
                    SearchController searchController();
                    SearchResultView searchResultView(stdObject);
                    break;
                case '3':
                    SortingController sortingController();
                    SortResultView sortResultView(stdVector[]);
                    break;
                case '4':
                    std::cout << "프로그램 종료\n";
                    fileController.save(stdVector[]);
                    start = false;
                    break;
                default:
                    std::cout << "input error\n";
            }
        }
    }
};