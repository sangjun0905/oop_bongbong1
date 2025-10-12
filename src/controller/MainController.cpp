#include "MainController.hpp"

#include <iostream>
#include <memory>
#include <string>

#include "FileController.hpp"
#include "MainMenuController.hpp"

MainController::MainController(const std::string& fname) : filename(fname) {}

void MainController::run() {
    FileController fileController(this->filename);
    this->studentList = fileController.readFile(this->studentList);

    std::unique_ptr<Controller> current = std::make_unique<MainMenuController>(studentList);
    while (current) {
        current->display();

        std::string userSel;
        std::getline(std::cin, userSel);

        auto next = current->nextController(userSel);
        if (!next) {
            std::cout << "exit program\n";
            fileController.save(this->studentList);
            break;
        }
        current = std::move(next);
    }
}
