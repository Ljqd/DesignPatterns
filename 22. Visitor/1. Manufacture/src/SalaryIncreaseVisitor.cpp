#include "SalaryIncreaseVisitor.h"

#include "SalesPerson.h"
#include "Manager.h"
#include "ITSupport.h"

SalaryIncreaseVisitor::SalaryIncreaseVisitor(double percentage) 
    : percentage(percentage) {}

void SalaryIncreaseVisitor::visitSalesPerson(SalesPerson& employee) 
{
    employee.setSalary(employee.getSalary() * (1.0 + percentage / 100.0));
}

void SalaryIncreaseVisitor::visitManager(Manager& employee) 
{
    employee.setSalary(employee.getSalary() * (1.0 + percentage / 100.0));
}

void SalaryIncreaseVisitor::visitITSupport(ITSupport& employee) 
{
    employee.setSalary(employee.getSalary() * (1.0 + percentage / 100.0));
}