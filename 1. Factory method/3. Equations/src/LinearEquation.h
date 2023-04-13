#pragma once#pragma once

#include <vector>
#include <string>

#include "BaseEquation.h"

class LinearEquation : public BaseEquation
{
public:
    LinearEquation(float a, float b);
    LinearEquation(const std::vector<float>& coefficients);

    BaseEquation::ComplexSolutions solve() override;
    std::string getEquationAsString() const override;

private:
    float a, b;
};