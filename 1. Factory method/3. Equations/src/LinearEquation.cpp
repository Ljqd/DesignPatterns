#include "LinearEquation.h"

LinearEquation::LinearEquation(float a, float b) : a{ a }, b{ b }
{
    if (a == 0 && b == 0)
        throw("LinearEquation: a == b == 0;");
}

LinearEquation::LinearEquation(const std::vector<float>& coefficients) :
    a{ coefficients[1] }, b{ coefficients[0] }
{

}

std::vector<float> LinearEquation::solve()
{
    std::vector<float> result;
    if (a == 0)
        result = {};
    else
        result = { - b / a };
    return result;
}

std::string LinearEquation::getEquationAsString() const
{
    std::string as = std::to_string(a);
    as.erase(as.find_first_of('.') + 3, std::string::npos);
    std::string bs = std::to_string(b);
    bs.erase(bs.find_first_of('.') + 3, std::string::npos);

    return as + "x + " + bs + " = 0";
}

size_t LinearEquation::degree() const
{
    // helps to define type of ane equation from BaseEquation class
    // could use enum {  Linear Quadratic BuQuadratic } but degree() also works fine.
    return 1;
}