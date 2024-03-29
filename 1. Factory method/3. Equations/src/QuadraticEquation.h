#pragma once

#include <vector>
#include <string>

#include "BaseEquation.h"
#include "LinearEquation.h"

class QuadraticEquation : public BaseEquation
{
public:
    QuadraticEquation(float a, float b, float c);
    QuadraticEquation(const std::vector<float>& coefficients);

    std::vector<float> solve() override;
    std::string getEquationAsString() const override;
    size_t degree() const override;

private:
    float a, b, c;
};