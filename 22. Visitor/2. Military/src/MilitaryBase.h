#pragma once

#include "MilitaryObject.h"

class MilitaryBase : public MilitaryObject 
{
public:
    void accept(SpyVisitor& visitor) override;
};