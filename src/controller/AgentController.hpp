#pragma once
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>
#include <sstream>
#include <fstream>
#include "../llama/LLM.hpp"

class AgentController {
private:
    const std::string model_path;
    std::string userInput;
    std::string appDescription;
    std::unique_ptr<LLM> model; 
    int flag;
public:
    //before create method is executed, store the model path 
    AgentController(std::string path) : model_path(std::move(path)), flag(0) {}

    //after constructor is executed, create LLM instance
    bool create()
    {
        try {
            model = std::make_unique<LLM>(model_path);
            loadAppDescription();
            flag = 1;
            return true;
        } catch (const std::exception& e) {
            std::cerr << "Failed to initialize agent: " << e.what() << std::endl;
            model.reset();
            flag = 0;
            return false;
        }
    };   

    std::string generate(const std::string& output) {
        if (!model) {
            throw std::logic_error("Agent model is not initialized. Call create() first.");
        }
        flag += 1;
        const std::string systemPrompt = R"(역할: 콘솔 StudentInfoSystem에 **입력만** 제공하는 에이전트.
반드시 지킬 것:
1) 한 프롬프트당 **한 줄**, **값만** 출력. 설명/기호/따옴표/마크다운/콜론/접두사 금지. 앞뒤 공백 금지. **마지막에 줄바꿈 1개**.
2) 표/메시지/정렬 결과 등이 나올 경우에는 반드시 **"exit"** 출력.
3) 메인 메뉴는 **1~4만** 허용. 화면에 "5. Agent Mode"가 보여도 **선택 금지**.
4) 작업 완료 판정 규칙 — 아래 조건 중 하나라도 보이면 이번 차례에는 `exit`만 1줄 출력하고 종료한다.
   ・ 화면에 `NO RESULTS FOUND`, `Sorting completed`가 포함되거나 검색 결과 표가 모두 출력된 직후
   ・ `사용자 요청`이 종료 의도를 담고 있을 때(예: “끝”, “그만”, “exit” 등)
5) 위 조건으로 작업을 마쳤다면, 바로 이어서 다시 메뉴 화면이 떠도 **추가 지시가 없는 한** 절대 다른 값을 반복 입력하지 말고 `exit` 한 줄로 종료한다.
6) 모델은 이전 대화를 저장하지 않는다. 항상 현재 `[SCREEN]`과 `사용자 요청`에 근거해 단계와 목표 달성 여부를 판단하라.
7) insertion은 Telephone까지 제대로 입력 된 이후에만 **"exit"** 출력
상태 → 허용 형식(정규식):
- 메인 메뉴(화면에 1~4와 '>'가 보임): `^[1-4]$`
- 검색 메뉴(`--- Search ---` + 1~6 + '>'): `^[1-6]$`
- 삽입 단계: Name `^[A-Za-z]{1,15}$` / StudentID `^\d{10}$` / BirthYear `^\d{4}$` / Department `^[A-Za-z]{1,23}$` / Tel `^\d{1,12}$`
- 검색 키워드: Name `^[A-Za-z]{1,15}$` / StudentID `^\d{1,10}$` / Admission `^\d{4}$` / Birth `^\d{4}$` / Department `^[A-Za-z]{1,23}$`
오류/재입력 규칙:
- `Try again!` 또는 `Error:` 직후에는 **같은 단계**를 위 정규식에 맞춰 **다시 1줄**만 출력.
- `Error : Already inserted`가 보이면 해당 삽입은 **종료**. 메인 메뉴로 돌아온 뒤에만 값을 입력.1ㄷ
금지 목록:
- 백틱, 따옴표(' "), 레이블(Name:, Answer: 등), 불필요한 공백, 2개 이상 줄바꿈, 이모지, 마크다운.
예시 시나리오(반드시 따를 것):

[SCREEN]
NO RESULTS FOUND
<end_of_turn>
[/SCREEN]
<start_of_turn>user
한 줄로 **값만** 출력하라.
사용자 요청: 2 학번 학생들 찾아줘
<end_of_turn>
<start_of_turn>model
exit

[SCREEN]
Sorting completed
<end_of_turn>
[/SCREEN]
<start_of_turn>user
한 줄로 **값만** 출력하라.
사용자 요청: 8888학번 학생들 찾아줘
<end_of_turn>
<start_of_turn>model
exit )";

        std::ostringstream builder;
        builder << "<start_of_turn>system\n"
                << systemPrompt;

        if (!appDescription.empty()) {
            builder << "\n\n앱 설명:\n" << appDescription;
        }

        builder << "\n<end_of_turn>\n"
                << "<start_of_turn>user\n"
                << "[SCREEN]\n"
                << output << "\n"
                << "[/SCREEN]\n"
                << "한 줄로 **값만** 출력하라.\n";

        if (!userInput.empty()) {
            builder << "사용자 요청: " << userInput << "\n";
        }

        builder << "<end_of_turn>\n"
                << "<start_of_turn>model\n";

        std::string allstring = builder.str();
        
        try {
            std::string result = model->generate(allstring);
            return result;
        } catch (const std::exception& e) {
            std::cerr << "Agent generation failed: " << e.what() << std::endl;
            zeroFlag();
            return "exit";
        }
    };

    int getFlag() {
        return flag;
    };

    void zeroFlag() {
        flag = 0;
        model.reset();
    };
    
    void setUserInput() {
        std::getline(std::cin, userInput);

    }

    const std::string& getUserInput() {
        return userInput;
    }

private:
    void loadAppDescription() {
        const std::string specPath = "../AppSpec.md";
        std::ifstream specFile(specPath);

        if (!specFile.is_open()) {
            appDescription.clear();
            std::cerr << "Warning: Unable to open " << specPath << " for app description.\n";
            return;
        }

        std::ostringstream buffer;
        buffer << specFile.rdbuf();
        appDescription = buffer.str();
    }
};
