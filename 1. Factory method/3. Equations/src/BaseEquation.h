#pragma once

#include <string>
#include <complex>
#include <vector>
#include <cmath>


class BaseEquation
{
public:
    // other way I need to do it throuh std::variant: (float, vector(float, float), vector<complex, complex>, ...)
    using ComplexSolutions = std::vector<std::complex<float>>;

    virtual ComplexSolutions solve() = 0;
    virtual std::string getEquationAsString() const = 0;
};