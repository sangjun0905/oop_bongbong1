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
    std::unique_ptr<AgentController> agentController;

public:
    MainController(const std::string& fname) : filename(fname) {}

    void run() {
        FileController fileController(this->filename);
        this->studentList = fileController.readFile(this->studentList);


        Controller controller(studentList, MainMenuView());
        while (true) {
            std::string output = controller.display();
            std::string userSel;
            std::cin >> userSel;

            if (agentController.getFlag()) {
                std::string prompt = output +  "\nUser input: " + userSel + "\n";
                userSel = agentController.generate(prompt);
            }
            else {
                std::cin >> userSel;
            }

            if (output.find("Main Menu") == std::string::npos && userSel == "5") {
                std::cout << "\n>>> Agent 모드 활성화!\n"
                agentController = std::make_unique<AgentController>("..\\external\\llama.cpp\\models\\Expbox77\\gemma-3-12b-it-Ko-Reasoning-Q4_K_M-GGUF");
                agentController.create();
            }
            if (output.find("Main Menu") != std::string::npos && userSel == "4") {
                std::cout << "Exit program.\n";
                fileController.save(this->studentList);
                break;
            }

            controller = controller.nextController(userSel);
        }
    }
};
