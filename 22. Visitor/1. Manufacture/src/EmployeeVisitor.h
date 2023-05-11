#pragma once

class Manager;
class SalesPerson;
class ITSupport;

class EmployeeVisitor
{
public:
    virtual void visitSalesPerson(SalesPerson& employee) = 0;
    virtual void visitManager(Manager& employee) = 0;
    virtual void visitITSupport(ITSupport& employee) = 0;
};