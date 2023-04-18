#pragma once

#include <string>
#include <vector>
#include <cmath>
#include <memory>


class BaseEquation
{
public:
    virtual std::vector<float> solve() = 0;
    virtual std::string getEquationAsString() const = 0;
    virtual size_t degree() const = 0;

    virtual std::unique_ptr<BaseEquation> clone() = 0;
};