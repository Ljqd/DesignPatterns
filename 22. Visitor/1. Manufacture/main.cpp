#include <iostream>

#include "src/Organization.h"

#include "src/SalesPerson.h"
#include "src/ITSupport.h"
#include "src/Manager.h"

#include "src/SalaryIncreaseVisitor.h"
#include "src/FineVisitor.h"

int main()
{
    Organization organization = {};

    SalesPerson salesPerson1 = { 1000 };
    SalesPerson salesPerson2 = { 1000 };
    SalesPerson salesPerson3 = { 1000 };
    SalesPerson salesPerson4 = { 1000 };
    SalesPerson salesPerson5 = { 1000 };

    Manager manager = { 2500 };

    ITSupport support1 = { 500 };
    ITSupport support2 = { 5000 };

    organization.addEmployee(&salesPerson1);
    organization.addEmployee(&salesPerson2);
    organization.addEmployee(&salesPerson3);
    organization.addEmployee(&salesPerson4);
    organization.addEmployee(&salesPerson5);
    organization.addEmployee(&manager);
    organization.addEmployee(&support1);
    organization.addEmployee(&support2);

    // yes, generally we must create own visitors for different employees
    // but - for this, demonstrational exercise it doesn't have any sense,
    // just additional code with zero idea-practice

    SalaryIncreaseVisitor salaryIncreaseVisitor = { 20 };
    FineVisitor fineVisitor = { 200 };

    double baseSalary = organization.getTotalSalary();

    std::cout << organization.getTotalSalary() << std::endl << std::endl;
    
    organization.applyVisitor(salaryIncreaseVisitor);
    std::cout << organization.getTotalSalary() << std::endl;
    std::cout << baseSalary * 1.2 << std::endl << std::endl;
    baseSalary = organization.getTotalSalary();

    organization.applyVisitor(fineVisitor);
    std::cout << organization.getTotalSalary() << std::endl;
    std::cout << baseSalary - 200 * 8 << std::endl;
}

