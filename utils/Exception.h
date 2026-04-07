//
// Created by ntt12 on 4/3/2026.
//

#ifndef POINT_OF_SALE_EXCEPTION_H
#define POINT_OF_SALE_EXCEPTION_H
#include <stdexcept>

class EntityNotFoundException : public std::runtime_error{
public:
    EntityNotFoundException() : std::runtime_error("ID does not exist in the system"){}
};


#endif //POINT_OF_SALE_EXCEPTION_H