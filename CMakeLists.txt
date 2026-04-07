cmake_minimum_required(VERSION 4.1)
project(Point_of_Sale)

set(CMAKE_CXX_STANDARD 20)

add_executable(Point_of_Sale main.cpp
        utils/Exception.cpp
        utils/Exception.h
        Product.cpp
        Product.h
        DatabaseSRC/DBContext/DBContext.cpp
        DatabaseSRC/DBContext/DBContext.h
        Menu.cpp
        Menu.h
        DatabaseSRC/Repo/ProductRepo.cpp
        DatabaseSRC/Repo/ProductRepo.h
        MenuController.cpp
        MenuController.h
        DatabaseSRC/Repo/CategoriesRepo.cpp
        DatabaseSRC/Repo/CategoriesRepo.h
        Categories.cpp
        Categories.h
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
        ProductVariants.cpp
        ProductVariants.h
        DatabaseSRC/Repo/PVRepo.cpp
        DatabaseSRC/Repo/PVRepo.h
        Modifiers.cpp
        Modifiers.h
)

target_link_libraries(Point_of_Sale PRIVATE odbc32)

if (MSVC)
    add_compile_options(/EHsc)
endif()