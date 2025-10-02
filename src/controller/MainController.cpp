#include <iostream>

#include "../model/StudentList.hpp"
#include "../view/MainMenuView.hpp"
#include "../view/InsertionView.hpp"
#include "../view/SortView.hpp"
// #include "SearchModule.hpp"
#include "InsertionController.hpp"
#include "FileController.hpp"

class MainController {
private:
    std::string filename;
public:
    MainController(const std::string& fname) : filename(fname){}
    StudentList studentList;
    MainMenuView menuView;
    InsertionView insertionView;
    
    void run() {
        
      
        
        FileController fileController(filename);
        StudentList readfileStudent = fileController.readFile(studentList);
        InsertionController insertionController(insertionView);        
    
        

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
                    SortView sortView;
                    sortView.display();
                    //SortController sortController(sortView.display());
                    // sortView.resultDisplay() //임시
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