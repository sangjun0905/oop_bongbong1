#include "InsertionController.hpp"

InsertionController::InsertionController(StudentList& list)
    : BaseController(list)
{
    // --- 체인 구성 ---
    auto nameController = std::make_shared<InsertNameController>(list);
    auto idController = std::make_shared<InsertStudentIDController>(list);
    auto birthController = std::make_shared<InsertBirthController>(list);
    auto finalController = std::make_shared<FinalAddController>(list);

    // --- 연결 ---
    nameController->setNext(idController);
    idController->setNext(birthController);
    birthController->setNext(finalController);

    // 체인 시작점 지정
    head = nameController;
}

void InsertionController::execute(Student& student) {
    if (head) {
        head->execute(student); // 첫 단계 실행
    }
}
