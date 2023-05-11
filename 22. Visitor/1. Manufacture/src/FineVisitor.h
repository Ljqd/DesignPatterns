#pragma once

#include "EmployeeVisitor.h"

class Manager;
class SalesPerson;
class ITSupport;

class FineVisitor : public EmployeeVisitor
{
public:
    FineVisitor(double fineAmount);

    void visitSalesPerson(SalesPerson& employee) override;
    void visitManager(Manager& employee) override;
    void visitITSupport(ITSupport& employee) override;
private:
    double fineAmount;
};