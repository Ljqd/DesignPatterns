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
        return processSingleSolution(solutions1);
    }

    solutions1[0] = sqrt(solutions1[0]);
    solutions1[1] = sqrt(solutions1[1]);

    std::vector<float> solutions2 = { -1.0f * solutions1[0], -1.0f * solutions1[1]};
    // check unique solutions: t^2 = {-1, 1} -> x = {-1, 1, 1, -1};
    if (std::find(solutions1.begin(), solutions1.end(), solutions2[0]) == solutions1.end())
        solutions1.push_back(solutions2[0]);
    if (std::find(solutions1.begin(), solutions1.end(), solutions2[1]) == solutions1.end())
        solutions1.push_back(solutions2[1]);

    return solutions1;
}

std::string BiQuadraticEquation::getEquationAsString() const
{
    return std::to_string(a) + "x^4 + " + std::to_string(b) + "x^2 + " + std::to_string(c) + " = 0";
}

std::vector<float> BiQuadraticEquation::processSingleSolution(std::vector<float>& solutions)
{
    if (solutions[0] <= 0)
        return std::vector<float>{};

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

    solutions1.insert(solutions1.begin(), solutions1.end(), solutions1.begin());

    std::unordered_set<int> unique_set;
    for (const auto& elem : solutions1)
        unique_set.insert(elem);
    for (const auto& elem : solutions2)
        unique_set.insert(elem);

    std::vector<float> result(unique_set.begin(), unique_set.end());

    std::sort(result.begin(), result.end());
    return result;
}