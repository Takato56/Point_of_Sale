//
// Created by admin on 4/7/2026.
//

#ifndef POINT_OF_SALE_STAFFCONTROLLER_H
#define POINT_OF_SALE_STAFFCONTROLLER_H
#include "../model/Repo/StaffRepo.h"


class StaffController {
    StaffRepo sr;
public:
    StaffController(DBContext& db) : sr(db) {};
    void login();
};


#endif //POINT_OF_SALE_STAFFCONTROLLER_H