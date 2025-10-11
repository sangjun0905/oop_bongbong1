#ifndef BASECONTROLLER_HPP
#define BASECONTROLLER_HPP

#include <memory>
#include "../model/Student.hpp"
#include "../model/StudentList.hpp"

class BaseController {
protected:
    std::shared_ptr<BaseController> next; // 다음 컨트롤러
    StudentList& studentList;              // 모든 컨트롤러에서 공유

public:
    explicit BaseController(StudentList& list);
    virtual ~BaseController() = default;

    // 다음 컨트롤러를 연결
    void setNext(std::shared_ptr<BaseController> nextController);

    // 각 컨트롤러가 반드시 구현해야 하는 실행 메서드
    virtual void execute(Student& student) = 0;
};

#endif
