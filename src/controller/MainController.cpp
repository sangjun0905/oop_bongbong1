#include <iostream>

#include "../model/StudentList.hpp"
#include "../view/MainMenuView.hpp"
#include "../view/InsertionView.hpp"
#include "../controller/SearchController.hpp"
#include "InsertionController.hpp"
//#include "../controller/SortingController.hpp"
#include "FileController.hpp"

class MainController {
public:
    StudentList studentList;
    MainMenuView menuView;
    
    void run() {
        InsertionView insertionView;
        InsertionController insertionController(insertionView, studentList);        

        SearchView searchView;
        SearchResultView searchResultView;
        SearchController searchController(searchView, searchResultView);
        
        //SortingView sortingView;
        //SortingController sortingController(new Display(), &studentList);
        //SortingResultView sortingResultView;

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
                case '2': {
                    /*
                    char SearchOption = searchView.display();
                    if (SearchOption == '7') break;  // 7번은 메인메뉴
                    std::vector<Student> Search_List = searchController.run(SearchOption);
                    searchResultView.displaySearchResults(Search_List);
                    */
                    searchController.run();
                    //SearchResultView searchResultView();
                    break;
                }
                case '3': {
                    
                    //SortingController sortingController();
                    //SortResultView sortResultView();
                    break;
                }
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