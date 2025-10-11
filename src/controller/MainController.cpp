#pragma once
#include <iostream>
#include <memory>
#include <string>

#include "../model/StudentList.hpp"

#include "../view/MainMenuView.hpp"
#include "../view/InsertionView.hpp"
#include "../view/SearchView.hpp"
#include "../view/SortSelView.hpp"
#include "../view/SortResultView.hpp"

#include "Controller.hpp"
#include "MainMenuController.hpp"
#include "InsertionController.hpp"
#include "SearchController.hpp"
#include "SortController.hpp"
#include "FileController.hpp"

class MainController {
private:
    StudentList studentList;
    std::string filename;

public:
    MainController(const std::string& fname) : filename(fname) {}

    void run() {
        FileController fileController(this->filename);
        this->studentList = fileController.readFile(this->studentList);

        bool running = true;
        while (running) {
            MainMenuView mainMenuView;
            mainMenuView.display();

            std::cout << "Select Menu: ";
            char mainSelect;
            std::cin >> mainSelect;

            std::unique_ptr<Controller> next = nullptr;

            switch (mainSelect) {
                case '1': {
                    InsertionView insertionView;
                    InsertionController insertionController(this->studentList, insertionView);

                    insertionController.display();
                    std::cout << "Input: ";
                    std::string insertSel;
                    std::cin >> insertSel;

                    next = insertionController.nextController(insertSel);
                    while (next) {
                        next->display();
                        std::cout << "Input: ";
                        std::string userInput;
                        std::cin >> userInput;
                        next = next->nextController(userInput);
                    }
                    break;
                }


                case '2': {
                    SearchView searchView;
                    SearchController searchController(this->studentList, searchView);

                    searchController.display();
                    std::cout << "Input search obtion: ";
                    std::string searchSel;
                    std::cin >> searchSel;

                    next = searchController.nextController(searchSel);
                    while (next) {
                        next->display();
                        std::cout << "Input: ";
                        std::string userInput;
                        std::cin >> userInput;
                        next = next->nextController(userInput);
                    }
                    break;
                }

                
                case '3': {
                    SortSelectionView sortSelView;
                    SortSelectionController sortController(this->studentList, sortSelView);

                    sortController.display();
                    std::cout << "Input sort obtion: ";
                    std::string sortSel;
                    std::cin >> sortSel;

                    next = sortController.nextController(sortSel);
                    while (next) {
                        next->display();
                        next = next->nextController();
                    }
                    break;
                }

          
                case '4': {
                    std::cout << "Exit program.\n";
                    fileController.save(this->studentList);
                    running = false;
                    break;
                }

                case '5': {
                    
                }

                default:
                    std::cout << "Wrong Input.\n";
                    break;
            }
        }
    }
};
