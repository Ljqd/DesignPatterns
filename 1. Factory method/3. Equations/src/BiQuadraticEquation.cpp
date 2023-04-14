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
    std::vector<float> solutions = temp.solve();
    
    // check non-emptiness
    if (solutions.size() == 0)
        return solutions;

    if (solutions.size() == 1)
    {
        return processSingleSolution(solutions);
    }

    return processMultipleSolution(solutions);
}

std::string BiQuadraticEquation::getEquationAsString() const
{
    return std::to_string(a) + "x^4 + " + std::to_string(b) + "x^2 + " + std::to_string(c) + " = 0";
}

std::vector<float> BiQuadraticEquation::processSingleSolution(std::vector<float>& solutions)
{
    if (solutions[0] < 0)
        return std::vector<float>{};
    if (solutions[0] == 0)
        return std::vector<float>{ 0.0 };

    float solution1 = sqrt(solutions[0]);
    float solution2 = -sqrt(solutions[0]);

    return std::vector<float>{ solution1, solution2 };
}

std::vector<float> BiQuadraticEquation::processMultipleSolution(std::vector<float>& solutions)
{
    // reuse code
    std::vector<float> temp1 = { solutions[0] };
    std::vector<float> temp2 = { solutions[1] };

    std::vector<float> solutions1 = processSingleSolution(temp1);
    std::vector<float> solutions2 = processSingleSolution(temp2);

    solutions1.insert(solutions1.end(), solutions2.begin(), solutions2.begin());

    std::unordered_set<float> uniqueSet = {};
    for (const auto& elem : solutions1)
        uniqueSet.insert(elem);
    for (const auto& elem : solutions2)
        uniqueSet.insert(elem);

    std::vector<float> result(uniqueSet.begin(), uniqueSet.end());

    std::sort(result.begin(), result.end());
    return result;
}