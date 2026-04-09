#include "LoginController.h"

LoginResult LoginController::login() {
    LoginResult result;

    std::string pin;
    std::cout << "Enter PIN: ";
    std::cin >> pin;

    std::vector<Employee> employees = er.getAll();

    for (const auto& emp : employees) {
        if (PasswordHasher::verify(pin, emp.getPinHash())) {
            result.isSuccess = true;
            result.staffId = emp.getEmployeeId();
            result.role = emp.getRole();
            result.empName = emp.getEmployeeName();
            return result;
        }
    }

    std::cout << "Login failed!\n";
    return result;
}