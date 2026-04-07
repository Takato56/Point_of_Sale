//
// Created by ntt12 on 4/3/2026.
//

#ifndef POINT_OF_SALE_PRODUCTREPO_H
#define POINT_OF_SALE_PRODUCTREPO_H

#include "../../Product.h"
#include <vector>
#include "../DBContext/DBContext.h"
#include "../../Categories.h"
class ProductRepo {
private:
    DBContext& db;
public:
    ProductRepo(DBContext& context) : db(context) {}
    void addProduct(const Product& pd);
    std::vector<Product> getAll();
    Product getByID(const std::string& id);
    void update(const Product& pd);
    void remove(const std::string& id);
};

#endif //POINT_OF_SALE_PRODUCTREPO_H