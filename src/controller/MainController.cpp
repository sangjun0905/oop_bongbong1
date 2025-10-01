#include <iostream>

#include "../model/StudentList.hpp"
#include "../view/MainMenuView.hpp"
#include "../view/InsertionView.hpp"
// #include "SearchModule.hpp"
#include "InsertionController.hpp"
// #include "SortingModule.hpp"
#include "FileController.hpp"

class MainController {
public:
    StudentList studentList;
    MainMenuView menuView;
    
    void run() {
        InsertionView insertionView;
        InsertionController insertionController(insertionView, studentList);        
        
        FileController fileController("text.txt");
        StudentList readfileStudent = fileController.readFile(studentList);

        bool start = true;
        while (start) {
            char userSelect = menuView.display();

            switch (userSelect) {
                case '1': {
                    insertionController.insert();
                    break;
                }
                case '2':
                    //SearchController searchController();
                    //SearchResultView searchResultView();
                    break;
                case '3':
                    //SortingController sortingController();
                    //SortResultView sortResultView();
                    break;
                case '4':
                    std::cout << "프로그램 종료\n";
                    fileController.save(studentList);
                    start = false;
                    break;
                default:
                    std::cout << "input error\n";
            }
        }
    }
};