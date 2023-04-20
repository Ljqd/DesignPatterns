#pragma once

#include <iostream>
#include <vector>

#include "Employee.h"
#include "Salesperson.h"

class Manager : public Employee
{
public:
    Manager(std::string name) : Employee(name) {};

    void payExpenses() override {
        std::cout << "-- Manager " << name << " is processing payExpenses() request...\n";
        for (Employee* subordinate : subordinates)
            subordinate->payExpenses();
        std::cout << "-- Manager " << name << " has completed payExpenses() request!" << std::endl;
    }

    void addSubordinate(Employee* subordinate) override {
        subordinates.push_back(subordinate);
    }

protected:
    std::vector<Employee*> subordinates;
};