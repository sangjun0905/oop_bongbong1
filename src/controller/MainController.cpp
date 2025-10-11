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


        Controller controller(studentList, MainMenuView());
        while (true) {
            std::string output = controller.display();
            
            if (Agent 모드면) {
                prompt = output + 유저 입력
                userSel = llm.generate(prompt);
            }
            else {
                std::string userSel;
                std::cin << userSel;
            }

            if (output이 mainMenu고 userSel이 5번이면) {
                llm 만들어요.
                Agent 모드네요.
            }
            if (output이 mainMenu고 userSel이 exit이면) {
                std::cout << "Exit program.\n";
                fileController.save(this->studentList);
                running = false;
                break;
            }

            controller = controller.nextController(userSel);
        }
    }
};
