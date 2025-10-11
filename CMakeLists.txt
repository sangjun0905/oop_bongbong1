cmake_minimum_required(VERSION 3.16)

# 프로젝트 이름과 언어 설정
project(StudentInfoSystem CXX)

# C++17 표준 사용
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_FILES
    src/main.cpp
    src/controller/FileController.cpp
    src/controller/InsertionController.cpp
    src/controller/SearchController.cpp
    src/controller/MainController.cpp
    src/model/Student.cpp
    src/model/StudentList.cpp
    src/view/InsertionView.cpp
    src/view/SearchView.cpp
    src/view/MainMenuView.cpp
    src/view/SortView.cpp
    src/controller/SortController.cpp
    src/llama/LLM.cpp
    src/controller/ChatbotController.cpp
)

# 실행 파일 타겟 정의
add_executable(StudentInfoSystem ${SRC_FILES})



# include 경로 설정 (헤더 파일 탐색을 위해 src 폴더 전체 등록)
target_include_directories(StudentInfoSystem PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

# (선택)  CUDA를 사용하고 싶다면 아래 주석을 해제하세요.
# set(LLAMA_CUBLAS ON)

# llama.cpp를 정적 라이브러리로 빌드하도록 명시합니다.
set(BUILD_SHARED_LIBS OFF)

# `external/llama.cpp` 폴더를 하위 프로젝트로 추가합니다.
# 이 명령으로 CMake는 저 폴더의 CMakeLists.txt를 읽고,
# `llama`라는 라이브러리 타겟을 인식하게 됩니다.
add_subdirectory(external/llama.cpp)

# 우리 프로그램(MyStudentApp)과 llama 라이브러리를 연결(link)합니다.
# 이제 우리 프로그램은 llama.cpp의 모든 함수를 사용할 수 있습니다.
target_link_libraries(StudentInfoSystem PRIVATE llama)


# 경고 옵션 (선택사항, 팀 규칙에 따라 추가/삭제 가능)
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(StudentInfoSystem PRIVATE -Wall -Wextra -pedantic)
elseif (MSVC)
    target_compile_options(StudentInfoSystem PRIVATE /W4)
endif()