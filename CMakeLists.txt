cmake_minimum_required(VERSION 4.1)
project(Point_of_Sale)

set(CMAKE_CXX_STANDARD 20)

add_executable(Point_of_Sale main.cpp
        utils/Exception.cpp
        utils/Exception.h
        Model/entity/Product.cpp
        Model/entity/Product.h
        Model/DatabaseSRC/DBContext/DBContext.cpp
        Model/DatabaseSRC/DBContext/DBContext.h
        Menu.cpp
        Menu.h
        Model/DatabaseSRC/Repo/ProductRepo.cpp
        Model/DatabaseSRC/Repo/ProductRepo.h
        MenuController.cpp
        MenuController.h
        Model/DatabaseSRC/Repo/CategoriesRepo.cpp
        Model/DatabaseSRC/Repo/CategoriesRepo.h
        Model/entity/Categories.cpp
        Model/entity/Categories.h
        PasswordHasher.cpp
        PasswordHasher.h
        Model/entity/Employee.cpp
        Model/entity/Employee.h
        Model/entity/Manager.cpp
        Model/entity/Manager.h
        StaffController.cpp
        StaffController.h
        Model/DatabaseSRC/Repo/StaffRepo.cpp
        Model/DatabaseSRC/Repo/StaffRepo.h
        Model/DatabaseSRC/DBContext/DBContext.h
        Model/DatabaseSRC/DBContext/DBContext.h
)

target_link_libraries(Point_of_Sale PRIVATE odbc32)

if (MSVC)
    add_compile_options(/EHsc)
endif()