#pragma once

#include "../model/StudentList.hpp"
#include "../view/InsertionView.hpp"

class InsertionController
{
private:
    StudentList& studentModel;
    InsertionView& insertionView;

public:
    InsertionController(InsertionView& insertionView, StudentList& studentModel);
    ~InsertionController();

    void insert();
};

#pragma once

#include "../model/StudentList.hpp"
#include "../view/InsertionView.hpp"

class InsertionController
{
private:
    InsertionView& insertionView;

public:
    InsertionController(InsertionView& insertionView);
    ~InsertionController();

    StudentList& insert(StudentList& studentList);
};
