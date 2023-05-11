#pragma once

class GeneralStaff;
class MilitaryBase;

class SpyVisitor
{
public:
    virtual void visitGeneralStaff(GeneralStaff& object) = 0;
    virtual void visitMilitaryBase(MilitaryBase& object) = 0;
};