#include <iostream>

#include "../model/StudentModel.hpp"
#include "../view/MainMenuView.hpp"
#include "../view/InsertionView.hpp"
// #include "SearchModule.hpp"
#include "InsertionController.hpp"
// #include "SortingModule.hpp"
#include "FileController.hpp"

class MainController {
public:
    StudentModel studentModel;
    MainMenuView menuView;
    
    void run() {
        InsertionView insertionView;
        InsertionController insertionController(insertionView, studentModel);        
        
        FileController fileController("text.txt");
        vector<Student> readfileStudent = fileController.readfile();

        for (const Student& student : readfileStudent) {
            studentModel.addStudent(student);
        }

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
                    fileController.writefile(studentModel.getAllStudents());
                    start = false;
                    break;
                default:
                    std::cout << "input error\n";
            }
        }
    }
};