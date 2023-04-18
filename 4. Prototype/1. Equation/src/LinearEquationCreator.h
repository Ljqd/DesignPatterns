#pragma once

#include "BaseEquationCreator.h"
#include "LinearEquation.h"

class LinearEquationCreator : public BaseEquationCreator
{
public:
    std::unique_ptr<BaseEquation> getEquation(const std::vector<float>& coefficient) override;
};