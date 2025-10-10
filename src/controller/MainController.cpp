#include <iostream>

#include "../model/StudentList.hpp"
#include "../view/MainMenuView.hpp"
#include "../view/InsertionView.hpp"
#include "../view/SearchView.hpp"
#include "../view/SortView.hpp"
// #include "SearchModule.hpp"
#include "InsertionController.hpp"
#include "SearchController.hpp"
#include "FileController.hpp"
#include "SortController.hpp"
#include "ChatbotController.hpp"

class MainController {
private:
    std::string filename;
public:
    MainController(const std::string& fname) : filename(fname){}
    StudentList studentList;
    MainMenuView menuView;
    InsertionView insertionView;
    SortView sortView;
    
    void run() {
    
        SearchView searchView;
        
        FileController fileController(filename);
        studentList = fileController.readFile(studentList);
        InsertionController insertionController(insertionView);        
        SearchController searchController(searchView);
        

        bool start = true;
        while (start) {
            char userSelect = menuView.display();

            switch (userSelect) {
                case '1': {
                    studentList = insertionController.insert(studentList);
                    break;
                }
                case '2':
                    searchController.search(studentList);
                    break;
                case '3':
                    {
                        SortController sortController(sortView, studentList);
                    }
                    
                    break;
                case '4':{
                    std::cout << "exit program\n";
                    fileController.save(studentList);
                    start = false;
                    break;
                }
                case '5':{ //view - controller 만들어서 처리해야 함(아직 미구현)
                    std::cout << "chatbot mode\n";
                    ChatbotController chatbotController;
                    std::string user_question;
                    std::cout << "Ask a question to the chatbot (type 'exit' to quit): ";
                    while (true) {
                        //buffer 비우기
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::getline(std::cin, user_question);
                        if (user_question == "exit") {
                            break;
                        }
                        chatbotController.handleUserInput(user_question);
                        std::cout << "Ask another question (type 'exit' to quit): ";
                    }


                }   

                default:{
                    std::cout << "input error\n";
                }
            }
        }
    }
};