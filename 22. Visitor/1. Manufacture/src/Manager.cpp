#include "Manager.h"

Manager::Manager(double salary) : salary(salary) {}

void Manager::accept(EmployeeVisitor& visitor) 
{ 
    visitor.visitManager(*this); 
};

double Manager::getSalary() const 
{ 
    return salary; 
}

void Manager::setSalary(double newSalary) 
{ 
    salary = newSalary; 
}