#pragma once

#include <vector>
#include <string>
#include <algorithm>

#include "BaseEquation.h"
#include "QuadraticEquation.h"

class BiQuadraticEquation : public BaseEquation
{
public:
    BiQuadraticEquation(float a, float b, float c);
    BiQuadraticEquation(const std::vector<float>& coefficients);

    std::vector<float> solve() override;
    std::string getEquationAsString() const override;

private:
    float a, b, c;
};