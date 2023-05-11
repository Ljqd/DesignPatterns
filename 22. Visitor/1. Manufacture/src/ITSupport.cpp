#include "ITSupport.h"

ITSupport::ITSupport(double salary) : salary(salary) {}

void ITSupport::accept(EmployeeVisitor& visitor) 
{ 
    visitor.visitITSupport(*this); 
};

double ITSupport::getSalary() const 
{ 
    return salary; 
}

void ITSupport::setSalary(double newSalary) 
{ 
    salary = newSalary; 
}