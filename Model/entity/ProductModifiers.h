//
// Created by ntt12 on 4/8/2026.
//

#ifndef POINT_OF_SALE_PRODUCTMODIFIERS_H
#define POINT_OF_SALE_PRODUCTMODIFIERS_H
#include <string>
#include <iostream>

class ProductModifiers {
private:
    int PMId;
    int ProdId;
    int ModId;
public:
    ProductModifiers() : PMId(), ProdId(), ModId() {}

    int getPMId() const;
    int getProdId() const;
    int getModId() const;

    void setPMId(int newPMId);
    void setProdId(int newProdId);
    void setModId(int newModId);

    virtual void edit();
    virtual void display() const;
    virtual ~ProductModifiers() {}

};


#endif //POINT_OF_SALE_PRODUCTMODIFIERS_H