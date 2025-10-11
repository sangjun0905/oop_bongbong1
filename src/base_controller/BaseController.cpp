#include "BaseController.hpp"

BaseController::BaseController(StudentList& list)
    : studentList(list), next(nullptr) {}

void BaseController::setNext(std::shared_ptr<BaseController> nextController) {
    next = std::move(nextController);
}
