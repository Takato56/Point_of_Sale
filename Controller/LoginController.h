//
// Created by admin on 4/7/2026.
//

#ifndef POINT_OF_SALE_STAFFCONTROLLER_H
#define POINT_OF_SALE_STAFFCONTROLLER_H
#include "../Model/DatabaseSRC/DBContext/DBContext.h"
#include "../Model/entity/Employee.h"
#include "../Model/Repo/EmployeeRepo.h"
#include "../utils/PasswordHasher.h"
#include <iostream>
#include <string>

struct LoginResult {
    bool isSuccess = false;
    int staffId = -1;
    Role role = Staff;
    std::string empName;
};

class LoginController {
private:
    DBContext db;
    EmployeeRepo er;
public:
    explicit LoginController(DBContext& context) : db(context), er(context) {}
    LoginResult login();
};


#endif //POINT_OF_SALE_STAFFCONTROLLER_H