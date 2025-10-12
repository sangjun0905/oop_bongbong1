#pragma once
#include <stdexcept>
#include <iostream>
#include <memory>
#include <string>
#include <iostream>
#include "../llama/LLM.hpp"
#include "../view/AgentView.hpp"

class AgentController {
private:
    const std::string& model_path;
    std::unique_ptr<LLM> model; 
    int flag;
    AgentView agentView;
public:
    //before create method is executed, store the model path 
    AgentController(const std::string& path) : model_path(path) {
        flag = 0;
    };

    //after constructor is executed, create LLM instance
    void create()
    {
        model = std::make_unique<LLM>(model_path);
        flag = 1;
    };   

    //after create method is executed, use generate method
    std::string generate(const std::string& output) {
        if (!model) {
            throw std::logic_error("Agent model is not initialized. Call create() first.");
        }
        flag += 1;
        const std::string prompt = 
            "역할: 콘솔 StudentInfoSystem에 **입력만** 제공하는 에이전트.\
            반드시 지킬 것:\
            1) 한 프롬프트당 **한 줄**, **값만** 출력. 설명/기호/따옴표/마크다운/콜론/접두사 금지. 앞뒤 공백 금지. **마지막에 줄바꿈 1개**.\
            2) 표/메시지/정렬 결과 등은 모두 무시하고 **다음 입력 프롬프트**에만 반응.\
            3) 메인 메뉴는 **1~4만** 허용. 화면에 \"5. Agent Mode\"가 보여도 **선택 금지**.\
            상태 → 허용 형식(정규식):\
            - 메인 메뉴(화면에 1~4와 '>'가 보임): `^[1-4]$`\
            - 검색 메뉴(`--- Search ---` + 1~6 + '>'): `^[1-6]$`\
            - 삽입 단계: Name `^[A-Za-z]{1,15}$` / StudentID `^\\d{10}$` / BirthYear `^\\d{4}$` / Department `^[A-Za-z]{1,23}$` / Tel `^\\d{1,12}$`\
            - 검색 키워드: Name `^[A-Za-z]{1,15}$` / StudentID `^\\d{1,10}$` / Admission `^\\d{4}$` / Birth `^\\d{4}$` / Department `^[A-Za-z]{1,23}$`\
            오류/재입력 규칙:\
            - `Try again!` 또는 `Error:` 직후에는 **같은 단계**를 위 정규식에 맞춰 **다시 1줄**만 출력.\
            - `Error : Already inserted`가 보이면 해당 삽입은 **종료**. 메인 메뉴로 돌아온 뒤에만 값을 입력.\
            금지 목록:\
            - 백틱, 따옴표(' \"), 레이블(Name:, Answer: 등), 불필요한 공백, 2개 이상 줄바꿈, 이모지, 마크다운.\
            주어진 위의 프롬프트에서 해결할 수 없는 문제는 **exit**을 출력해줘";
        
        
        string allstring = prompt + output+ this->getUserInput();
        
        string result = model->generate(allstring);
        std::cout<<result<<endl;
        return result;
    };

    int getFlag() {
        return flag;
    };

    void zeroFlag() {
        flag = 0;
    };
    
    

    std::string getUserInput() {
        std::string input;
        input = agentView.display();
        return input;
    }

    
};