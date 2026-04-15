#include "LoginController.h"

LoginResult LoginController::login() {
    LoginResult result;
    StaffRepo sr(db);

    std::string phoneNumber;
    std::cout << "Enter phone number: ";
    std::cin >> phoneNumber;

    Employee emp = sr.getByPhone(phoneNumber);

    std::string pin;
    std::cout << "Enter PIN: ";
    std::cin >> pin;


    if (PasswordHasher::verify(pin, emp.getPinHash())) {
        result.isSuccess = true;
        result.staffId = emp.getId();
        result.role = emp.getRole();
        result.empName = emp.getName();
        return result;
    }

    return result;
}