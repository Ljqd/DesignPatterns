#pragma once

#include <string>
#include <vector>
#include <cmath>


class BaseEquation
{
public:
    virtual std::vector<float> solve() = 0;
    virtual std::string getEquationAsString() const = 0;
};