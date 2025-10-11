#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include "../model/Student.hpp"
#include "../model/StudentList.hpp"


using namespace std;

class FileController {

public:
    FileController(const string& filename) : file(filename) {};
    ~FileController() {};

     //파일을 읽어서 student vector 전달
    StudentList readFile(StudentList students)
    {
        ifstream readinfo;          //읽기 모드 파일
        readinfo.open(file);        //파일 열기
        if (!readinfo.is_open())    //파일이 열리지 않았을 경우(파일이 없거나 접근이 불가능할 경우)
        {
            //cout << "File does not exist. create a new file"<<endl; 
        //파일이 없으므로 새로 만들기
            ofstream createfile;
            createfile.open(file);
            if (!createfile.is_open())
            {
                //cout << "failed to create(open) new file"<<endl;
            }
            else {
                //cout << "succeed to create a new file" << endl;
                createfile.close();
                //새로 생성되었으므로 읽을 정보 없음 -> 닫기
            }
            return students;    // 기존 파일이 없으므로 기존 vector 전달
        }

        //파일이 열림(기존 파일이 존재함)
        string line;
        vector<string> split;
        while (getline(readinfo, line))
        {
            split = lineSplit(line);
            if (split.empty()) {     //잘못된 학생 정보일때 
                //cout << "wrong information" <<endl;
                continue;
            }
            Student one(split[0].c_str(), split[1].c_str(), split[4].c_str(), stoi(split[2]), split[3].c_str());
            students.addStudent(one);
        }
        readinfo.close();
        return sortByName(students);
    };


    //파일 쓰기
    void FileController::save(StudentList studentlist)
    {
        ofstream writeinfo;
        writeinfo.open(file);
        string delimiter = "::";    //구분자 (임의지정)

        if (!writeinfo.is_open())//파일 접근이 안될때
        {
            //cout << "failed to open file" << endl; 
            return;
        }
        for (int i = 0; i < studentlist.size(); i++)
        {
            Student student = studentlist.getStudent(i);
            writeinfo << student.getName() << delimiter;
            writeinfo << student.getStudentId() << delimiter;
            writeinfo << student.getBirthYear() << delimiter;
            writeinfo << student.getDepartment() << delimiter;
            writeinfo << student.getTel() << endl;
        }

        writeinfo.close();

        //cout << "file write success" << endl;
    };

private:

    string file;
    StudentList studentList;

    //파일에서 문자열을 읽어 student 형태로 만들어 반환 (파일읽기에서 사용)
    vector<string> lineSplit(string line)
    {
        string delimiter = "::";    //구분자(임의로 정함)

        vector<string> studvector;

        int start = 0;
        int del_index = 0;

        while ((del_index = line.find(delimiter, start)) != string::npos)   //string::npos-> no position, 찾는 값이 없음 -> 찾는 값이 있을 때 반복문
        {                                                                   //string.find(찾을 내용, 검색 시작 위치)-> 인덱스 반환
            string sub = line.substr(start, del_index - start);      //string.substr(시작 위치, 길이) delimiter index에서 복사 시작 index를 뺀 길이만큼 복사
            studvector.push_back(sub);
            start = del_index + delimiter.length();     //구분자 index에 구분자 길이를 더해 다음 시작 위치 업데이트
        }

        studvector.push_back(line.substr(start)); //마지막 남은 문장 추가

        if (wrongInfo(studvector) == 1) // 학생 정보 잘못됨
        {
            studvector.clear();
        }

        return studvector;
    };

    int wrongInfo(vector<string> studvector)
    {
        if (studvector.size() != 5) //문장을 쪼갠 결과 정보가 5개가 아님
            return 1;

        if (studvector[0].length() > 15)   //name의 글자수가 15 이상
            return 1;
        else
        {
            for (int i = 0; i < studvector[0].length(); i++)    //english character 판별
                if (!isalpha(studvector[0][i]))
                    return 1;
        }

        if (studvector[1].length() != 10)  //student id가 10글자가 아님
            return 1;
        else
        {
            for (int i = 0; i < studvector[1].length(); i++)    //숫자 판별
                if (!isdigit(studvector[1][i]))
                    return 1;
        }

        if (studvector[2].length() != 4) //birthyear가 4글자가 아님
            return 1;
        else
        {
            for (int i = 0; i < studvector[2].length(); i++)    //숫자 판별
                if (!isdigit(studvector[2][i]))
                    return 1;
        }

        if (studvector[3].length() > 63)
            return 1;

        if (studvector[4].length() > 12) //tel의 글자수가 12자 이상
            return 1;
        else
        {
            for (int i = 0; i < studvector[4].length(); i++)    //숫자 판별
                if (!isdigit(studvector[4][i]))
                    return 1;
        }

        return 0;
    };

    StudentList& sortByName(StudentList& stulist) {
        this->studentList = stulist;  
        auto& students = this->studentList.getAllStudents(); 
        sort(students.begin(), students.end(),[](const Student& a, const Student& b) {
            return string(a.getName()) < string(b.getName());
        });
        return this->studentList;
    };
    
};