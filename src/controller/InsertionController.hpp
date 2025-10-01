#pragma once

#include "../model/StudentModel.hpp"
#include "../view/InsertionView.hpp"

class InsertionController
{
private:
    StudentModel& studentModel;
    InsertionView& insertionView;

public:
    InsertionController(InsertionView& insertionView, StudentModel& studentModel);
    ~InsertionController();

    void insert();
};
