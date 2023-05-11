#pragma once

#include <vector>

#include "Employee.h"
#include "EmployeeVisitor.h"


class Organization
{
public:
    void addEmployee(Employee* employee) {
        employees.push_back(employee);
    }

    void applyVisitor(EmployeeVisitor& visitor) {
        for (Employee* employee : employees) {
            employee->accept(visitor);
        }
    }

    double getTotalSalary() const {
        double total = 0;
        for (const Employee* employee : employees) {
            total += employee->getSalary();
        }
        return total;
    }
private:
    std::vector<Employee*> employees;
};