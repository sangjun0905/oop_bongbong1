#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include "../model/Student.hpp"
#include "../model/StudentList.hpp"
#include "../view/FileView.hpp"


using namespace std;

class FileController
{
    string file;
    StudentList sortedStudentList;
    FileView fileView;


public:
    FileController(string file_name);   //생성자(파일명 초기화) argv값 전달 받음
    StudentList readFile(StudentList studentlist);         //파일을 읽어서 student vector 전달
    void save(StudentList students);   //파일 쓰기

private:
    vector<string> lineSplit(string line);     //파일에서 문자열을 읽어 student 형태로 만들어 반환 (파일읽기에서 사용)
    int wrongInfo(vector<string> studvector);
    StudentList& sortByName(StudentList& studentList);
};