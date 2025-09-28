#include <iostream>
#include "../src/view/MainMenuView.cpp"
#include "../src/view/InsertionView.cpp"

// 앞으로 SearchController, SortingController도 이런 식으로 include
// #include "SearchController.cpp"
// #include "SortingController.cpp"

class MainController {
public:
    void run() {
        MainMenuView menuView;
        InsertionView insertionView;

        bool start = true;
        while (start) {
            char userSelect = menuView.display();

            switch (userSelect) {
                case '1': {
                    insertionView.display();
                    // InsertionController insertionController(insertionView.getName, insertionView.getStudentID,
                                                            // insertionView.getBirthYear, insertionView.getDepartment, 
                                                            // insertionView.getTel)
                    break;
                }
                case '2':
                    // SearchController searchController()
                    // SearchResultView searchResultView(stdObject)
                    break;
                case '3':
                    // SortingController sortingController()
                    // SortResultView sortResultView(stdVector[])
                    break;
                case '4':
                    std::cout << "프로그램 종료\n";
                    // FileController fileController
                    // fileController.save(stdVector[])
                    start = false;
                    break;
                default:
                    std::cout << "input error\n";
            }
        }
    }
};