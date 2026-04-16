cmake_minimum_required(VERSION 4.1)
project(Point_of_Sale)

set(CMAKE_CXX_STANDARD 20)

add_executable(Point_of_Sale main.cpp
        # Controller
        Controller/LoginController.cpp
        Controller/LoginController.h
        Controller/EmployeeController.cpp
        Controller/EmployeeController.h
        Controller/ManagerController.cpp
        Controller/ManagerController.h

        # Model - Database
        Model/database/DBContext.cpp
        Model/database/DBContext.h

        # Model - Entity
        Model/entity/Product.cpp
        Model/entity/Product.h
        Model/entity/Categories.cpp
        Model/entity/Categories.h
        Model/entity/Staff.cpp
        Model/entity/Staff.h
        Model/entity/Modifiers.cpp
        Model/entity/Modifiers.h
        Model/entity/ProductVariants.cpp
        Model/entity/ProductVariants.h
        Model/entity/ProductModifiers.cpp
        Model/entity/ProductModifiers.h
        Model/entity/OrderItems.cpp
        Model/entity/OrderItems.h
        Model/entity/Customer.cpp
        Model/entity/Customer.h
        Model/entity/Orders.cpp
        Model/entity/Orders.h
        Model/entity/Discount.cpp
        Model/entity/Discount.h
        Model/entity/OrderDiscounts.cpp
        Model/entity/OrderDiscounts.h
        Model/entity/Payments.cpp
        Model/entity/Payments.h

        # Model - Repository
        Model/repository/ProductRepo.cpp
        Model/repository/ProductRepo.h
        Model/repository/CategoriesRepo.cpp
        Model/repository/CategoriesRepo.h
        Model/repository/StaffRepo.cpp
        Model/repository/StaffRepo.h
        Model/repository/PVRepo.cpp
        Model/repository/PVRepo.h
        Model/repository/PMRepo.cpp
        Model/repository/PMRepo.h
        Model/repository/CustomerRepo.cpp
        Model/repository/CustomerRepo.h
        Model/repository/OrderRepo.cpp
        Model/repository/OrderRepo.h
        Model/repository/PaymentRepo.cpp
        Model/repository/PaymentRepo.h
        Model/repository/OrderItemRepo.cpp
        Model/repository/OrderItemRepo.h
        Model/repository/DiscountRepo.cpp
        Model/repository/DiscountRepo.h
        Model/repository/ModifierRepo.cpp
        Model/repository/ModifierRepo.h

        # View
        View/EmployeeView.cpp
        View/EmployeeView.h
        View/ManagerView.cpp
        View/ManagerView.h
        View/MenuView.cpp
        View/MenuView.h

        # Utils
        utils/App.cpp
        utils/App.h
        utils/DataHelper.cpp
        utils/DataHelper.h
        utils/Exception.cpp
        utils/Exception.h
        utils/PasswordHasher.cpp
        utils/PasswordHasher.h
)

target_link_libraries(Point_of_Sale PRIVATE odbc32)

if (MSVC)
    add_compile_options(/EHsc)
endif()