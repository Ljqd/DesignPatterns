#pragma once

#include <vector>

#include "Employee.h"
#include "Salesperson.h"

class Director : public Employee
{
public:
    Director(std::string name) : Employee(name) {};

    void payExpenses() override {
        std::cout << "- Director " << name << " is processing payExpenses() request...\n";
        for (Employee* subordinate : subordinates)
            subordinate->payExpenses();
        std::cout << "- Director " << name << " has completed payExpenses() request!" << std::endl;
    }

    void addSubordinate(Employee* subordinate) override {
        subordinates.push_back(subordinate);
    }

protected:
    std::vector<Employee*> subordinates;
};