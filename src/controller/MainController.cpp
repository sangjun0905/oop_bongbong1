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
    const std::string filepath = "..\\external\\llama.cpp\\models\\gemma-3-12b-it-ko-reasoning-q4_k_m.gguf";
    AgentController llmController(filepath);

    std::unique_ptr<Controller> current = std::make_unique<MainMenuController>(studentList);
    while (current) {
        std::string output = current->display();

        std::string userSel;
        if(llmController.getFlag())
        {
            std::string prompt;
            prompt += output + llmController.getUserInput();
            userSel = llmController.generate(prompt);
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
            std::cout<<"\n>>> Agent mode on!"<<endl;
            llmController.create();
        }

        current = std::move(next);
    }
}
