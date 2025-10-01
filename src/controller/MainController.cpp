#include <iostream>

#include "../model/StudentList.hpp"
#include "../view/MainMenuView.hpp"
#include "../view/InsertionView.hpp"
// #include "SearchModule.hpp"
#include "InsertionController.hpp"
// #include "SortingModule.hpp"
#include "FileController.hpp"

class MainController {
private:
    std::string filename;
public:
    MainController(const std::string& fname) : filename(fname){}
    StudentList studentList;
    MainMenuView menuView;
    
    void run() {
        InsertionView insertionView;
        InsertionController insertionController(insertionView);        
        
        FileController fileController("text.txt");
        StudentList readfileStudent = fileController.readFile(studentList);

        bool start = true;
        while (start) {
            char userSelect = menuView.display();

            switch (userSelect) {
                case '1': {
                    studentList = insertionController.insert(studentList);
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
                case '4':{
                    std::cout << "exit program\n";
                    fileController.save(studentList);
                    start = false;
                    break;
                }
                default:
                    std::cout << "input error\n";
            }
        }
    }
};