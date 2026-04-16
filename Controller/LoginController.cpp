#include "LoginController.h"
#include <iostream>
#include <regex>

LoginResult LoginController::login() {
    LoginResult result;
    const std::regex phoneRegex("^[0-9]{10}$");

    std::string phoneNumber;
    do {
        std::cout << "Enter phone number: ";
        std::cin >> phoneNumber;
        if (!std::regex_match(phoneNumber, phoneRegex)) {
            std::cout << "Invalid phone number. Please enter a valid 10-digit phone number.\n";
        }
    } while (!std::regex_match(phoneNumber, phoneRegex));

    Staff stf = sr.getByPhone(phoneNumber);

    const std::regex pinRegex("^[0-9]{6}$");
    std::string pin;
    do {
        std::cout << "Enter PIN (6 digits): ";
        std::cin >> pin;
        if (!std::regex_match(pin, pinRegex)) {
            std::cout << "Invalid PIN. Please enter exactly 6 digits.\n";
        }
    } while (!std::regex_match(pin, pinRegex));

    if (PasswordHasher::verify(pin, stf.getPinHash())) {
        result.isSuccess = true;
        result.staffId = stf.getId();
        result.role = stf.getRole();
        result.empName = stf.getName();
    }

    return result;
}