cmake_minimum_required(VERSION 4.1)
project(Point_of_Sale)

set(CMAKE_CXX_STANDARD 20)

add_executable(Point_of_Sale main.cpp
        utils/Exception.cpp
        utils/Exception.h
        Product.cpp
        Product.h
        Beverage.cpp
        Beverage.h
        DatabaseSRC/DBContext/DBContext.cpp
        DatabaseSRC/DBContext/DBContext.h
        Menu.cpp
        Menu.h
        ProductRepo.cpp
        ProductRepo.h
        MenuController.cpp
        MenuController.h
        PasswordHasher.cpp
        PasswordHasher.h
        Employee.cpp
        Employee.h
        Manager.cpp
        Manager.h
        StaffController.cpp
        StaffController.h
        StaffRepo.cpp
        StaffRepo.h
)

target_link_libraries(Point_of_Sale PRIVATE odbc32)

if (MSVC)
    add_compile_options(/EHsc)
endif()