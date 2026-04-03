#include "DatabaseSRC/DBContext/DBContext.h"
int main() {
    DBContext db;
    // DB Connection
    std::string connStr =
        "DRIVER={SQL Server};"
        "SERVER=172.17.155.235,1433;"
        "DATABASE=POS;"
        "UID=groupmember;"
        "PWD=123456;"
        "Encrypt=no;";
    if (!db.connect(connStr)) return -1;

    return 0;

}
