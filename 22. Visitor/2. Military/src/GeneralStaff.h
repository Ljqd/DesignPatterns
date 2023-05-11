#pragma once

#include "MilitaryObject.h"

class GeneralStaff : public MilitaryObject 
{
public:
    void accept(SpyVisitor& visitor) override;
};