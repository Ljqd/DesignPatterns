#include "QuadraticEquation.h"

QuadraticEquation::QuadraticEquation(float a, float b, float c) : a{ a }, b{ b }, c{ c }
{}

QuadraticEquation::QuadraticEquation(const std::vector<float>& coefficients) :
    a{ coefficients[2] }, b{ coefficients[1] }, c{ coefficients[0] }
{}

std::vector<float> QuadraticEquation::solve()
{
    if (a == 0 && b == 0 && c == 0)
        return std::vector<float>{ INFINITY };

    if (a == 0)
        return LinearEquation(b, c).solve();

    float D = pow(b, 2) - 4 * a * c;

    std::vector<float> solutions;
    
    if (D < 0)
    {
        solutions = {};
        return solutions;
    }

    if (D == 0)
    {
        solutions = { -b / (2 * a) };
        return solutions;
    }

    float x1 = (-b + sqrt(D)) / (2 * a);
    float x2 = (-b - sqrt(D)) / (2 * a);

    if (x1 > x2)
        solutions = { x2, x1 };
    else
        solutions = { x1, x2 };

    return solutions;
}

std::string QuadraticEquation::getEquationAsString() const
{
    std::string as = std::to_string(a);
    as.erase(as.find_first_of('.') + 3, std::string::npos);
    std::string bs = std::to_string(b);
    bs.erase(bs.find_first_of('.') + 3, std::string::npos);
    std::string cs = std::to_string(c);
    cs.erase(cs.find_first_of('.') + 3, std::string::npos);

    return as + "x^2 + " + bs + "x + " + cs + " = 0";
}

size_t QuadraticEquation::degree() const
{
    // helps to define type of ane equation from BaseEquation class
    // could use enum {  Linear Quadratic BuQuadratic } but degree() also works fine.
    return 2;
}