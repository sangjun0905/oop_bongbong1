#include <iostream>
#include <memory>
#include <string>

#include "../model/StudentList.hpp"

#include "../view/MainMenuView.hpp"
#include "../view/InsertionView.hpp"
/*
#include "../view/SearchView.hpp"
#include "../view/SortSelView.hpp"
#include "../view/SortResultView.hpp"
*/

#include "Controller.hpp"
#include "MainMenuController.hpp"
#include "InsertionController.hpp"
#include "SearchController.hpp"
#include "SortController.hpp"
#include "FileController.hpp"
#include "AgentController.hpp"

class MainController {
private:
    StudentList studentList;
    std::string filename;

public:
    MainController(const std::string& fname) : filename(fname) {}

    void run() {
        FileController fileController(this->filename);
        this->studentList = fileController.readFile(this->studentList);
        string model_path = "..\\external\\llama.cpp\\models\\Expbox77/gemma-3-12b-it-Ko-Reasoning-Q4_K_M-GGUF";
        AgentController llmController(model_path);

        Controller controller(studentList, MainMenuView());

        std::string userSel;

        while (true) {
            std::string output = controller.display();
            
            if (llmController.getFlag() /*Agent 모드면(getflag가 0이 아니면)*/) {
                std::string prompt = output + llmController.getUserInput();
                userSel = llm.generate(prompt);
            }
            else {
                std::cin << userSel;
            }

            if (output=="mainMenu" && userSel == "5"/*output이 mainMenu고 userSel이 5번이면*/) {
                //llm 만들어요.
                //Agent 모드네요.
                llmController.create();
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
