#include "SalesPerson.h"

SalesPerson::SalesPerson(double salary) : salary(salary) {}

void SalesPerson::accept(EmployeeVisitor& visitor) 
{ 
    visitor.visitSalesPerson(*this); 
};

double SalesPerson::getSalary() const 
{ 
    return salary; 
}

void SalesPerson::setSalary(double newSalary) 
{ 
    salary = newSalary; 
}