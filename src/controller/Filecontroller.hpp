#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include <cstring>
#include "../model/Student.hpp"


using namespace std;

class FileController
{
    string file;

public:
    FileController(string file_name);   //생성자(파일명 초기화) argv값 전달 받음
    vector<Student> readfile();         //파일을 읽어서 student vector 전달
    void writefile(vector<Student> newinfo);    //파일 쓰기

private:
    vector<string> linesplit(string line);     //파일에서 문자열을 읽어 student 형태로 만들어 반환 (파일읽기에서 사용)
    int wronginfo(vector<string> studvector);
};