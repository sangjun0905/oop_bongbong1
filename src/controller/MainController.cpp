#include "MainController.hpp"

#include <iostream>
#include <memory>
#include <string>

#include "FileController.hpp"
#include "MainMenuController.hpp"
#include "AgentController.hpp"

MainController::MainController(const std::string& fname) : filename(fname) {}

void MainController::run() {
    FileController fileController(this->filename);
    this->studentList = fileController.readFile(this->studentList);
    AgentController agentController("../external/llama.cpp/models/gemma-3-12b-it-ko-reasoning-q4_k_m.gguf");

    std::unique_ptr<Controller> current = std::make_unique<MainMenuController>(studentList);
    while (current) {
        std::string output = current->display();

        std::string userSel;
        if (agentController.getFlag()) {
            userSel = "";
        } 
        else {
            std::getline(std::cin, userSel);
        }

        if ((output.find("Main Menu") != std::string::npos) and (userSel == "5")) {
            agentController.create();
        }

        auto next = current->nextController(userSel);
        if (!next) {
            std::cout << "exit program\n";
            fileController.save(this->studentList);
            break;
        }
        current = std::move(next);
    }
}
