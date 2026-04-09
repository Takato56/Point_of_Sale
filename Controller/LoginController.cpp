#include "LoginController.h"

LoginResult LoginController::login() {
    LoginResult result;
    StaffRepo sr(db);

    std::string pin;
    std::cout << "Enter PIN: ";
    std::cin >> pin;

    std::vector<Employee> employees = sr.getAll();

    for (const auto& emp : employees) {
        if (PasswordHasher::verify(pin, emp.getPinHash())) {
            result.isSuccess = true;
            result.staffId = emp.getId();
            sr.roleToString(emp.getRole());
            result.empName = emp.getName();
            return result;
        }
    }

    std::cout << "Login failed!\n";
    return result;
}