#include "Model/DatabaseSRC/DBContext/DBContext.h"
#include "Controller/LoginController.h"
#include "Controller/EmployeeController.h"
#include "Controller/ManagerController.h"
#include "Model/Repo/CategoriesRepo.h"
#include "Model/Repo/ProductRepo.h"
#include <iostream>

int main() {
    DBContext db;

    std::string connStr =
        "DRIVER={SQL Server};"
        "SERVER=26.171.75.112,1433;"
        "DATABASE=POS;"
        "UID=groupmember;"
        "PWD=123456;"
        "Encrypt=no;";

    std::cout << "Connecting database...\n";
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

    CategoriesRepo cr(db);
    ProductRepo pr(db);
    std::vector<Categories> listCt = cr.getAll();
    std::vector<Product> listPd = pr.getAll();

    if (loginResult.role == Manager) {
        ManagerController controller(db);
        // controller.setCurrentStaffId(loginResult.staffId); // nếu bạn thêm hàm này
        // controller.loadData(listCt, listPd);               // nếu cần
        std::cout << "Manager mode\n";
    } else if (loginResult.role == Staff) {
        EmployeeController controller(db);
        controller.loadData(listCt, listPd);
        controller.createOrder();
    } else {
        std::cout << "Unknown role.\n";
    }

    return 0;
}