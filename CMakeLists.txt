cmake_minimum_required(VERSION 4.1)
project(Point_of_Sale)

set(CMAKE_CXX_STANDARD 20)

add_executable(Point_of_Sale main.cpp
        # Controller
        controller/LoginController.cpp
        controller/LoginController.h
        controller/EmployeeController.cpp
        controller/EmployeeController.h
        controller/ManagerController.cpp
        controller/ManagerController.h

        # Model - Database
        model/database/DBContext.cpp
        model/database/DBContext.h

        # Model - Entity
        model/entity/Product.cpp
        model/entity/Product.h
        model/entity/Categories.cpp
        model/entity/Categories.h
        model/entity/Employee.cpp
        model/entity/Employee.h
        model/entity/Modifiers.cpp
        model/entity/Modifiers.h
        model/entity/ProductVariants.cpp
        model/entity/ProductVariants.h
        model/entity/ProductModifiers.cpp
        model/entity/ProductModifiers.h
        model/entity/OrderItems.cpp
        model/entity/OrderItems.h
        model/entity/Customer.cpp
        model/entity/Customer.h
        model/entity/Orders.cpp
        model/entity/Orders.h
        model/entity/Discount.cpp
        model/entity/Discount.h
        model/entity/OrderDiscounts.cpp
        model/entity/OrderDiscounts.h
        model/entity/Payments.cpp
        model/entity/Payments.h

        # Model - Repository
        model/repository/ProductRepo.cpp
        model/repository/ProductRepo.h
        model/repository/CategoriesRepo.cpp
        model/repository/CategoriesRepo.h
        model/repository/StaffRepo.cpp
        model/repository/StaffRepo.h
        model/repository/PVRepo.cpp
        model/repository/PVRepo.h
        model/repository/PMRepo.cpp
        model/repository/PMRepo.h
        model/repository/CustomerRepo.cpp
        model/repository/CustomerRepo.h
        model/repository/OrderRepo.cpp
        model/repository/OrderRepo.h
        model/repository/PaymentRepo.cpp
        model/repository/PaymentRepo.h
        model/repository/OrderItemRepo.cpp
        model/repository/OrderItemRepo.h

        # View
        view/Menu.cpp
        view/Menu.h
        view/EmployeeView.cpp
        view/EmployeeView.h
        view/ManagerView.cpp
        view/ManagerView.h
        view/MenuView.cpp
        view/MenuView.h

        # Utils
        utils/App.cpp
        utils/App.h
        utils/DataHelper.cpp
        utils/DataHelper.h
        utils/Exception.cpp
        utils/Exception.h
        utils/PasswordHasher.cpp
        utils/PasswordHasher.h
        Model/repository/DiscountRepo.cpp
        Model/repository/DiscountRepo.h
        Model/repository/ModifierRepo.cpp
        Model/repository/ModifierRepo.h
)

target_link_libraries(Point_of_Sale PRIVATE odbc32)

if (MSVC)
    add_compile_options(/EHsc)
endif()