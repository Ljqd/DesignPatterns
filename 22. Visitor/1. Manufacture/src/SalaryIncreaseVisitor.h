#pragma once

#include "EmployeeVisitor.h"

class Manager;
class SalesPerson;
class ITSupport;

class SalaryIncreaseVisitor : public EmployeeVisitor
{
public:
    SalaryIncreaseVisitor(double percentage);

    void visitSalesPerson(SalesPerson& employee) override;
    void visitManager(Manager& employee) override;
    void visitITSupport(ITSupport& employee) override;
private:
    double percentage;
};