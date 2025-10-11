#ifndef INSERTIONCONTROLLER_HPP
#define INSERTIONCONTROLLER_HPP

#include <memory>
#include "BaseController.hpp"
// #include "InsertNameController.hpp"
// #include "InsertStudentIDController.hpp"
// #include "InsertBirthController.hpp"
// #include "FinalAddController.hpp"
#include "../model/StudentList.hpp"

class InsertionController : public BaseController {
private:
    std::shared_ptr<BaseController> head; // 체인의 시작점

public:
    explicit InsertionController(StudentList& list);
    void execute(Student& student) override;
};

#endif