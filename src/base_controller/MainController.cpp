#pragma once
#include "Controller.hpp"
#include "InsertionController.hpp"
#include "SearchController.hpp"
#include "SortController.hpp"
#include "FileController.hpp"
#include "../view/MainMenuView.hpp"
#include "../view/InsertionView.hpp"
#include "../view/SearchView.hpp"
#include "../view/SortView.hpp"

#include <iostream>
#include <memory>

class MainController : public Controller {
public:
    MainMenuView& mainMenuView;
    std::string filename;

    MainController(StudentList& stuList, MainMenuView& mv, const std::string& fname)
        : Controller(stuList, mv), mainMenuView(mv), filename(fname) {}

    std::unique_ptr<Controller> nextController(char sel) override {
        FileController fileController(this->filename);

        this->studentList = fileController.readFile(this->studentList);

        bool running = true;

        std::unique_ptr<Controller> next = nullptr;


        while (running) {
            this->mainMenuView.display(); 

            std::cout << "메뉴 번호를 입력하세요: ";
            char userSelect;
            std::cin >> userSelect;

            switch (userSelect) {
                case '1': {
                    InsertionView insertionView;
                    next = std::make_unique<InsertionController>(
                        this->studentList,
                        insertionView
                    );
                    break;
                }
                case '2': {
                    SearchView searchView;
                    next = std::make_unique<SearchController>(
                        this->studentList,
                        searchView
                    );
                    break;
                }
                case '3': {
                    SortView sortView;
                    next = std::make_unique<SortController>(
                        this->studentList,
                        sortView
                    );
                    break;
                }
                case '4': {
                    std::cout << "프로그램을 종료합니다.\n";
                    fileController.save(this->studentList);
                    running = false;
                    next = nullptr;
                    break;
                }
                default:
                    std::cout << "잘못된 입력입니다.\n";
                    continue;
            }

            // 3️⃣ 하위 Controller 실행 (있을 때만)
            while (next) {
                next = next->nextController(userSelect);
            }
        }

        return nullptr; // 종료 시 nullptr 반환 (체인 종료)
    }
};
