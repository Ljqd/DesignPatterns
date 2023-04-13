#include "QuadraticEquation.h"

QuadraticEquation::QuadraticEquation(float a, float b, float c) : a{ a }, b{ b }, c{ c }
{
    if (a == 0 && b == 0 && c == 0)
        throw("LinearEquation: a == b == c == 0;");
}

QuadraticEquation::QuadraticEquation(const std::vector<float>& coefficients) :
    a{ coefficients[0] }, b{ coefficients[1] }, c{ coefficients[2] }
{}

std::vector<float> QuadraticEquation::solve()
{
    float D = pow(b, 2) - 4 * a * c;

    std::vector<float> solutions;
    
    if (D < 0)
    {
        solutions = {};
        return solutions;
    }

    float x1 = (-b + sqrt(D)) / (2 * a);
    float x2 = (-b - sqrt(D)) / (2 * a);

    solutions = { x1, x2 };

    return solutions;
}

std::string QuadraticEquation::getEquationAsString() const
{
    return std::to_string(a) + "x^2 + " + std::to_string(b) + "x + " + std::to_string(c) + " = 0";
}