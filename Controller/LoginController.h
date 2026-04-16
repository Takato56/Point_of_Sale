#ifndef POINT_OF_SALE_LOGINCONTROLLER_H
#define POINT_OF_SALE_LOGINCONTROLLER_H

#include "../Model/database/DBContext.h"
#include "../Model/entity/Staff.h"
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
    DBContext& db;
    StaffRepo sr;
public:
    explicit LoginController(DBContext& context) : db(context), sr(context) {}
    LoginResult login();
};

#endif //POINT_OF_SALE_LOGINCONTROLLER_H