#pragma once

#include <iostream>
#include "SpyVisitor.h"

class SecretAgent : public SpyVisitor 
{
public:
    void visitGeneralStaff(GeneralStaff& object) override;
    void visitMilitaryBase(MilitaryBase& object) override;
};