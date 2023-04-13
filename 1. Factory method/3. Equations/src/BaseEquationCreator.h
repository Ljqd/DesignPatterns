#pragma once

#include <vector>
#include <memory>

#include "BaseEquation.h"

class BaseEquationCreator
{
public:
    virtual std::unique_ptr<BaseEquation> getEquation(const std::vector<float>& coefficient) = 0;
};