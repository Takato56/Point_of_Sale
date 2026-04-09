cmake_minimum_required(VERSION 4.1)
project(Point_of_Sale)

set(CMAKE_CXX_STANDARD 20)

add_executable(Point_of_Sale main.cpp
        controller/StaffController.cpp
        controller/StaffController.h
        controller/MenuController.cpp
        controller/MenuController.h
        utils/Exception.cpp
        utils/Exception.h
        utils/PasswordHasher.cpp
        utils/PasswordHasher.h
        model/DatabaseSRC/DBContext/DBContext.cpp
        model/DatabaseSRC/DBContext/DBContext.h
        model/entity/Product.cpp
        model/entity/Product.h
        model/entity/Categories.cpp
        model/entity/Categories.h
        model/entity/Employee.cpp
        model/entity/Employee.h
        model/entity/Manager.cpp
        model/entity/Manager.h
        model/entity/Modifiers.cpp
        model/entity/Modifiers.h
        model/entity/ProductVariants.cpp
        model/entity/ProductVariants.h
        model/Repo/ProductRepo.cpp
        model/Repo/ProductRepo.h
        model/Repo/CategoriesRepo.cpp
        model/Repo/CategoriesRepo.h
        model/Repo/StaffRepo.cpp
        model/Repo/StaffRepo.h
        model/Repo/PVRepo.cpp
        model/Repo/PVRepo.h
        view/Menu.cpp
        view/Menu.h
        Model/Repo/PMRepo.h
        Model/Repo/PMRepo.cpp
        Controller/EmployeeController.h
        Controller/EmployeeController.cpp
        Model/entity/ProductModifiers.cpp
        Model/entity/ProductModifiers.h
        utils/Uuid.cpp
        utils/Uuid.h
        main1.cpp
)

target_link_libraries(Point_of_Sale PRIVATE odbc32)

if (MSVC)
    add_compile_options(/EHsc)
endif()