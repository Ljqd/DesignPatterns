#include "LinearEquation.h"

LinearEquation::LinearEquation(float a, float b) : a{ a }, b{ b }
{
    if (a == 0 && b == 0)
        throw("LinearEquation: a == b == 0;");
}

LinearEquation::LinearEquation(const std::vector<float>& coefficients) :
    a{ coefficients[0] }, b{ coefficients[1] }
{

}

BaseEquation::ComplexSolutions LinearEquation::solve()
{
    BaseEquation::ComplexSolutions result = { { -b / a, 0 } };
    return result;
}

std::string LinearEquation::getEquationAsString() const
{
    return std::to_string(a) + "x + " + std::to_string(b) + " = 0";
}