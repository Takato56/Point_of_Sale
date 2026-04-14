//
// Created by admin on 4/7/2026.
//

#ifndef POINT_OF_SALE_STAFFCONTROLLER_H
#define POINT_OF_SALE_STAFFCONTROLLER_H

#include "../model/database/DBContext.h"
#include "../Model/entity/Employee.h"
#include "../utils/PasswordHasher.h"
#include "../Model/repository/StaffRepo.h"
#include <string>


struct LoginResult {
    bool isSuccess = false;
    int staffId = -1;
    Role role = Role_Staff;
    std::string empName;
};

class LoginController {
private:
    DBContext db;
    StaffRepo sr;
public:
    explicit LoginController(DBContext& context) : db(context), sr(context) {}
    LoginResult login();
};


#endif //POINT_OF_SALE_STAFFCONTROLLER_H