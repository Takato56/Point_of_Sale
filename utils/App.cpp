#include "App.h"
#include "../Model/DatabaseSRC/DBContext/DBContext.h"
#include "../Controller/LoginController.h"
#include "../Controller/EmployeeController.h"
#include "../Controller/ManagerController.h"
#include <iostream>

int runApp() {
    DBContext db;

    std::string connStr =
        "DRIVER={SQL Server};"
        "SERVER=26.171.75.112,1433;"
        "DATABASE=POS;"
        "UID=groupmember;"
        "PWD=123456;"
        "Encrypt=no;";

    if (!db.connect(connStr)) {
        std::cout << "Connect DB failed!\n";
        return -1;
    }

    LoginController loginController(db);
    LoginResult loginResult = loginController.login();

    if (!loginResult.isSuccess) {
        std::cout << "Invalid login.\n";
        return 0;
    }

    std::cout << "Welcome, " << loginResult.empName << "!\n";

    if (loginResult.role == Role_Manager) {
        ManagerController controller(db);
        controller.run();
        return 0;
    }

    if (loginResult.role == Role_Staff) {
        EmployeeController controller(db);
        controller.setCurrentStaffId(loginResult.staffId);
        controller.run();
        return 0;
    }

    std::cout << "Unknown role.\n";
    return 0;
}