#pragma once

#include "EmployeeVisitor.h"

class Employee
{
public:
    virtual void accept(EmployeeVisitor& visitor) = 0;
    virtual double getSalary() const = 0;
    virtual void setSalary(double newSalary) = 0;
};