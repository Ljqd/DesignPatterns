#pragma once

#include "BaseEquationCreator.h"
#include "QuadraticEquation.h"

class QuadraticEquationCreator : public BaseEquationCreator
{
public:
    std::unique_ptr<BaseEquation> getEquation(const std::vector<float>& coefficient) override;
};