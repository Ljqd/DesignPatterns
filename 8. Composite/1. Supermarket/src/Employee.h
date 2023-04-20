#pragma once

#include <string>

class Employee
{
public:
    Employee(std::string name) : name(name) {};

    virtual std::string getName() const {
        return name;
    }

    virtual void setName(std::string name) {
        this->name = name;
    }

    virtual void payExpenses() = 0;
    virtual void addSubordinate(Employee* subordinate) = 0;

protected:
    std::string name;
};