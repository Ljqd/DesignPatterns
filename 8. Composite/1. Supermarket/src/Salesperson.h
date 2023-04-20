#pragma once

#include <iostream>

#include "Employee.h"

class Salesperson : public Employee
{
public:
    Salesperson(std::string name) : Employee(name) {};

    void payExpenses() override {
        std::cout << "--- " << name << ": expenses has been paid.\n";
    }

    void addSubordinate(Employee* subordinate) override {
        // Don't implement this method because Salesperson is a leaf
        // or replace this with exception
        return;
    }
};