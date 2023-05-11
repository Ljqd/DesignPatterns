#pragma once

#include <iostream>
#include "SpyVisitor.h"

class Saboteur : public SpyVisitor 
{
public:
    void visitGeneralStaff(GeneralStaff& object) override;
    void visitMilitaryBase(MilitaryBase& object) override;
};