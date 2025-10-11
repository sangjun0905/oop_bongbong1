#include <iostream>

#include "../model/StudentList.hpp"
#include "../view/MainMenuView.hpp"
#include "../view/InsertionView.hpp"
#include "../view/SearchView.hpp"
#include "../view/SortView.hpp"

#include "InsertionController.hpp"
#include "SearchController.hpp"
#include "FileController.hpp"
#include "SortController.hpp"
#include "AgentController.hpp"

class MainController {
private:
    std::string filename;
public:
    MainController(const std::string& fname) : filename(fname){}
    StudentList studentList;
    MainMenuView menuView;
    InsertionView insertionView;
    SortView sortView;
    
    void run() {
    
        SearchView searchView;
        
        FileController fileController(filename);
        studentList = fileController.readFile(studentList);
        InsertionController insertionController(insertionView);        
        SearchController searchController(searchView);
        AgentController agentController;
        

        bool start = true;
        while (start) {

            char userSelect = menuView.display();

            switch (userSelect) {
                case '1': {
                    studentList = insertionController.insert(studentList);
                    break;
                }
                case '2': {
                    searchController.search(studentList);
                    break;
                }
                case '3': {
                    SortController sortController(sortView, studentList);
                    break;
                }
                case '4': {
                    std::cout << "exit program\n";
                    fileController.save(studentList);
                    start = false;
                    break;
                }
                case '5': {
                    agentController.agent();
                }
                default:
                    std::cout << "input error\n";
            }
        }
    }
};