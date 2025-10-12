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
    const std::string filepath = "../external/llama.cpp/models/gemma-3-12b-it-ko-reasoning-q4_k_m.gguf";
    AgentController llmController(filepath);

    std::unique_ptr<Controller> current = std::make_unique<MainMenuController>(studentList);
    while (current) {
        std::string output = current->display();

        std::string userSel;
        if(llmController.getFlag())
        {
            userSel = llmController.generate(output);
            auto pos = userSel.find_last_not_of("\r\n");
            if (pos == std::string::npos) userSel.clear();   // 전부 개행이면 빈 문자열
            else userSel.erase(pos + 1);

            std::cout << userSel << std::endl;
            if(userSel.find("exit")!=std::string::npos || llmController.getFlag()>8)
            {
                llmController.zeroFlag();
                continue;
            }
        }
        else{
            std::getline(std::cin, userSel);
        }

        auto next = current->nextController(userSel);
        if (!next) {
            std::cout << "exit program\n";
            fileController.save(this->studentList);
            break;
        }
        
        if(userSel == "5" && (output.find("Main Menu") != std::string::npos))
        {
            std::cout << "\n>>> Agent mode on!" << std::endl;
            if (llmController.create()) {
                llmController.setUserInput();
            } else {
                std::cout << ">>> Agent mode unavailable. Returning to manual input." << std::endl;
            }
        }

        current = std::move(next);
    }
}
