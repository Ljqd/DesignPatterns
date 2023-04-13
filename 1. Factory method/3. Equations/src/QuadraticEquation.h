#pragma once

#include <vector>
#include <string>

#include "BaseEquation.h"

class QuadraticEquation : public BaseEquation
{
public:
    QuadraticEquation(float a, float b, float c);
    QuadraticEquation(const std::vector<float>& coefficients);

    std::vector<float> solve() override;
    std::string getEquationAsString() const override;

private:
    float a, b, c;
};