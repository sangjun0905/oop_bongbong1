#pragma once
#include <iostream>
#include <memory>
#include "FileController.hpp"
#include "MainMenuController.hpp"
#include "InsertionController.hpp"
#include "SearchController.hpp"
#include "SortController.hpp"
#include "../view/MainMenuView.hpp"
#include "../view/InsertionView.hpp"
#include "../view/SearchView.hpp"
#include "../view/SortView.hpp"

class MainController {
private:
    std::string filename;
    StudentList studentList;
    MainMenuView mainMenuView;

public:
    MainController(const std::string& fname)
        : filename(fname) {}

    void run() {
        // 1️⃣ 파일 로드
        FileController fileController(this->filename);
        this->studentList = fileController.readFile(this->studentList);

        bool running = true;
        while (running) {
            MainMenuView mainMenuView;
            MainMenuController mainMenuController(this->studentList, this->mainMenuView);
            mainMenuController.display(); // 메뉴 표시만

            // 3️⃣ 사용자 입력
            std::cout << "메뉴 번호를 입력하세요: ";
            char mainSelect;
            std::cin >> mainSelect;

            std::unique_ptr<Controller> next = nullptr;

            switch (mainSelect) {
                // === ① 삽입 ===
                case '1': {
                    InsertionView insertionView;
                    InsertionController insertionController(this->studentList, insertionView);

                    insertionController.display(); // View 출력

                    std::cout << "삽입: ";
                    char insertSel;
                    std::cin >> insertSel;

                    next = insertionController.nextController(insertSel);
                    while (next) next = next->nextController(insertSel);
                    break;
                }

                // === ② 검색 ===
                case '2': {
                    SearchView searchView;
                    SearchController searchController(this->studentList, searchView);

                    searchController.display();

                    std::cout << "검색 옵션 선택: ";
                    char searchSel;
                    std::cin >> searchSel;

                    next = searchController.nextController(searchSel);
                    while (next) next = next->nextController(searchSel);
                    break;
                }

                // === ③ 정렬 ===
                case '3': {
                    SortView sortView;
                    SortController sortController(this->studentList, sortView);

                    sortController.display();

                    std::cout << "정렬 기준 선택: ";
                    char sortSel;
                    std::cin >> sortSel;

                    next = sortController.nextController(sortSel);
                    while (next) next = next->nextController(sortSel);
                    break;
                }

                // === ④ 종료 ===
                case '4': {
                    std::cout << "프로그램을 종료합니다.\n";
                    fileController.save(this->studentList);
                    running = false;
                    break;
                }

                // === ❌ 예외 ===
                default:
                    std::cout << "잘못된 입력입니다.\n";
                    break;
            }
        }
    }
};
