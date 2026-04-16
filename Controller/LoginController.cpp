#include "LoginController.h"
#include <regex>

LoginResult LoginController::login() {
    LoginResult result;
    StaffRepo sr(db);
    const std::regex phoneRegex("^[0-9]{10}$");

    std::string phoneNumber;
    do {
        std::cout << "Enter phone number: ";
        std::cin >> phoneNumber;
        if (!std::regex_match(phoneNumber, phoneRegex)) {
            std::cout << "Invalid phone number. Please enter a valid phone number starts with 0 and contain 10 digits.\n";
        }
    } while (!std::regex_match(phoneNumber, phoneRegex));

    Employee emp = sr.getByPhone(phoneNumber);

    const std::regex pinRegex("^[0-9]{6}$");
    std::string pin;
    do {
        std::cout << "Enter PIN (contains 6 digits): ";
        std::cin >> pin;
        if (!std::regex_match(pin, pinRegex)) {
            std::cout << "Invalid PIN. Please enter a valid PIN with 6 digits.\n";
        }
    } while (!std::regex_match(pin, pinRegex));

    if (PasswordHasher::verify(pin, emp.getPinHash())) {
        result.isSuccess = true;
        result.staffId = emp.getId();
        result.role = emp.getRole();
        result.empName = emp.getName();
        return result;
    }

    return result;
}
