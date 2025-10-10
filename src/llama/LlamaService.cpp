#include "LlamaService.hpp"
#include <cstdio>    // _popen, _pclose, fgets를 위해
#include <stdexcept> // 예외 처리를 위해
#include <array>

// 생성자 구현
LlamaService::LlamaService(const std::string& model_path) {
    // 우리 프로젝트 폴더 구조에 맞게 경로를 고정합니다.
    llama_executable_path_ = "..\\llama_engine\\llama-cli.exe";
    model_path_ = "..\\llama_engine\\models\\" + model_path;
}

// 'ask' 메소드의 상세 구현
std::string LlamaService::ask(const std::string& prompt) {
    // 1. llama.cpp를 실행할 전체 명령어 문자열을 만듭니다.
    //    프롬프트에 따옴표가 포함될 수 있으므로 이스케이프 처리가 필요하지만,
    //    여기서는 설명을 위해 간단하게 구성합니다.
    std::string command = llama_executable_path_ +
                          " -m " + model_path_ +
                          " -p \"" + prompt + "\"" +
                          " -n 128"; // 답변 최대 길이는 128 토큰으로 제한

    // 2. _popen으로 외부 프로그램을 실행하고, 그 출력 결과를 읽어올 파이프를 엽니다.
    FILE* pipe = _popen(command.c_str(), "r"); // Windows에서는 _popen, macOS/Linux에서는 popen -> 수정 예정
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }

    // 3. 파이프에서 나오는 결과를 한 번에 128바이트씩 읽어와 result 변수에 계속 추가합니다.
    std::array<char, 128> buffer;
    std::string result = "";
    while (fgets(buffer.data(), buffer.size(), pipe) != nullptr) {
        result += buffer.data();
    }
    
    // 4. 파이프를 닫고 결과를 반환합니다.
    _pclose(pipe); // Windows에서는 _pclose, macOS/Linux에서는 pclose

    // llama.cpp의 출력에는 프롬프트가 다시 포함되므로, 실제 답변만 잘라내야 할 수 있습니다.
    // (이 부분은 llama.cpp 출력 형식에 맞춰 후처리가 필요할 수 있습니다)

    return result;
}