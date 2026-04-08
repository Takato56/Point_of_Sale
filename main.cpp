#include "Controller/MenuController.h"
#include "model/DatabaseSRC/DBContext/DBContext.h"

int main() {
    DBContext db;
    // DB Connection
    std::string connStr =
        "DRIVER={SQL Server};"
        "SERVER=26.171.75.112,1433;"
        "DATABASE=POS;"
        "UID=groupmember;"
        "PWD=123456;"
        "Encrypt=no;";
    if (!db.connect(connStr)) return -1;

    MenuController controller(db);
    controller.run();

    return 0;

}
