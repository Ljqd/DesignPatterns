#pragma once

#include "Employee.h"
#include "EmployeeVisitor.h"

class Manager : public Employee
{
public:
    Manager(double salary);

    void accept(EmployeeVisitor& visitor) override;
    double getSalary() const override;
    void setSalary(double newSalary) override;
private:
    double salary;
};