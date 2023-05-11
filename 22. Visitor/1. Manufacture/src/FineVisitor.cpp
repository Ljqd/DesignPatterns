#include "FineVisitor.h"

#include "SalesPerson.h"
#include "Manager.h"
#include "ITSupport.h"

FineVisitor::FineVisitor(double fineAmount) : fineAmount(fineAmount) {}

void FineVisitor::visitSalesPerson(SalesPerson& employee)
{
    employee.setSalary(employee.getSalary() - fineAmount);
}

void FineVisitor::visitManager(Manager& employee)
{
    employee.setSalary(employee.getSalary() - fineAmount);
}

void FineVisitor::visitITSupport(ITSupport& employee)
{
    employee.setSalary(employee.getSalary() - fineAmount);
}