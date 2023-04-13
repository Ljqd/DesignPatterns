#pragma once

#include <vector>
#include <string>

#include "BaseEquation.h"
#include "QuadraticEquation.h"

class BiQuadraticEquation : public BaseEquation
{
public:
    BiQuadraticEquation(float a, float b, float c);
    BiQuadraticEquation(const std::vector<float>& coefficients);

    BaseEquation::ComplexSolutions solve() override;
    std::string getEquationAsString() const override;

private:
    float a, b, c;
};