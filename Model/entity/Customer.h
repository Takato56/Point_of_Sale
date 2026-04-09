//
// Created by ntt12 on 4/8/2026.
//

#ifndef POINT_OF_SALE_CUSTOMER_H
#define POINT_OF_SALE_CUSTOMER_H
#include <string>
#include <iostream>

class Customer {
private:
    int CustId, Point;
    std::string CustName, CustPhone;
public:
    Customer() : CustId(), Point(0), CustName(""), CustPhone("") {}

    std::string getCustName() const;
    std::string getCustPhone() const;
    int getCustId() const;
    int getPoint() const;

    void setCustName(std::string newCustName);
    void setCustPhone(std::string newCustPhone);
    void setCustId(int newCustId);
    void setPoint(int newPoint);

    virtual void edit();
    std::string toString() const;
    virtual ~Customer();
};


#endif //POINT_OF_SALE_CUSTOMER_H