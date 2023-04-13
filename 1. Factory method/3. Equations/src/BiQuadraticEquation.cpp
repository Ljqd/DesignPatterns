#include "BiQuadraticEquation.h"


BiQuadraticEquation::BiQuadraticEquation(float a, float b, float c) : a{ a }, b{ b }, c{ c }
{
    if (a == 0 && b == 0 && c == 0)
        throw("LinearEquation: a == b == c == 0;");
}

BiQuadraticEquation::BiQuadraticEquation(const std::vector<float>& coefficients) :
    a{ coefficients[2] }, b{ coefficients[1] }, c{ coefficients[0] }
{}

std::vector<float> BiQuadraticEquation::solve()
{
    // replace t = x^2 and solve
    QuadraticEquation temp = { a, b, c };
    std::vector<float> solutions1 = temp.solve();
    
    // check non-emptiness
    if (solutions1.size() == 0)
        return solutions1;

    if (solutions1.size() == 1)
    {
        solutions1.push_back(-1.0f * solutions1[0]);
        return solutions1;
    }

    std::vector<float> solutions2 = { -1.0f * solutions1[0], -1.0f * solutions1[1]};
    // check unique solutions: t^2 = {-1, 1} -> x = {-1, 1, 1, -1};
    if (std::find(solutions1.begin(), solutions1.end(), solutions2[0]) != solutions1.end())
        solutions1.push_back(solutions2[0]);
    if (std::find(solutions1.begin(), solutions1.end(), solutions2[1]) != solutions1.end())
        solutions1.push_back(solutions2[1]);

    return solutions1;
}

std::string BiQuadraticEquation::getEquationAsString() const
{
    return std::to_string(a) + "x^2 + " + std::to_string(b) + "x + " + std::to_string(c) + " = 0";
}