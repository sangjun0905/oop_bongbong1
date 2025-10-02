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
)

# 실행 파일 타겟 정의
add_executable(StudentInfoSystem ${SRC_FILES})

# include 경로 설정 (헤더 파일 탐색을 위해 src 폴더 전체 등록)
target_include_directories(StudentInfoSystem PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

# 경고 옵션 (선택사항, 팀 규칙에 따라 추가/삭제 가능)
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(StudentInfoSystem PRIVATE -Wall -Wextra -pedantic)
elseif (MSVC)
    target_compile_options(StudentInfoSystem PRIVATE /W4)
endif()