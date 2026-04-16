#ifndef POINT_OF_SALE_EMPLOYEE_H
#define POINT_OF_SALE_EMPLOYEE_H
#include <string>

enum Role {
    Role_Staff = 1,
    Role_Manager = 2
};

class Staff {
private:
    int stfId = 0;
    std::string stfName;
    std::string stfPhoneNumber;
    std::string pinHash;
    Role role = Role_Staff;
    int isActive = 1;
public:
    Staff() = default;

    [[nodiscard]] int getId() const;
    void setId(int id);
    [[nodiscard]] const std::string& getName() const;
    void setName(const std::string& name);
    [[nodiscard]] const std::string& getPhoneNumber() const;
    void setPhoneNumber(const std::string& phoneNumber);
    [[nodiscard]] const std::string& getPinHash() const;
    void setPinHash(const std::string& pinHash);
    [[nodiscard]] Role getRole() const;
    void setRole(Role newRole);
    [[nodiscard]] int getIsActive() const;
    void setIsActive(int isActive);

    [[nodiscard]] std::string toString() const;

    virtual ~Staff() = default;
};

#endif //POINT_OF_SALE_EMPLOYEE_H