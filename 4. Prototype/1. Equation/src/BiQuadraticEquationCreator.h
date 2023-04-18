#pragma once

#include "BaseEquationCreator.h"
#include "BiQuadraticEquation.h"

class BiQuadraticEquationCreator : public BaseEquationCreator
{
public:
    std::unique_ptr<BaseEquation> getEquation(const std::vector<float>& coefficient) override;
};