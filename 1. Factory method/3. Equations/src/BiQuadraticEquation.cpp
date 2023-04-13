#include "BiQuadraticEquation.h"


BiQuadraticEquation::BiQuadraticEquation(float a, float b, float c) : a{ a }, b{ b }, c{ c }
{
    if (a == 0 && b == 0 && c == 0)
        throw("LinearEquation: a == b == c == 0;");
}

BiQuadraticEquation::BiQuadraticEquation(const std::vector<float>& coefficients) :
    a{ coefficients[0] }, b{ coefficients[1] }, c{ coefficients[2] }
{}

BaseEquation::ComplexSolutions BiQuadraticEquation::solve()
{
    // t = x^2
    QuadraticEquation temp = { a, b, c };
    ComplexSolutions solutions1 = temp.solve();
    ComplexSolutions solutions2 = { -1.0f * solutions1[0], -1.0f * solutions1[1]};

    // don't check unique solutions
    solutions1.insert(std::end(solutions1), std::begin(solutions2), std::end(solutions2));

    return solutions1;
}

std::string BiQuadraticEquation::getEquationAsString() const
{
    return std::to_string(a) + "x^2 + " + std::to_string(b) + "x + " + std::to_string(c) + " = 0";
}