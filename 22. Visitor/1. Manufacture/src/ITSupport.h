#pragma once

#include "Employee.h"
#include "EmployeeVisitor.h"

class ITSupport : public Employee
{
public:
    ITSupport(double salary);

    void accept(EmployeeVisitor& visitor) override;
    double getSalary() const override;
    void setSalary(double newSalary) override;
private:
    double salary;
};