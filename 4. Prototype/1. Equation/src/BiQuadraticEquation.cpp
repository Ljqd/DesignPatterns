#include "BiQuadraticEquation.h"


BiQuadraticEquation::BiQuadraticEquation(float a, float b, float c) : a{ a }, b{ b }, c{ c }
{}

BiQuadraticEquation::BiQuadraticEquation(const std::vector<float>& coefficients) :
    a{ coefficients[2] }, b{ coefficients[1] }, c{ coefficients[0] }
{}

std::vector<float> BiQuadraticEquation::solve()
{
    if (a == 0 && b == 0 && c == 0)
        return std::vector<float>{ INFINITY };

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
    std::string as = std::to_string(a);
    as.erase(as.find_first_of('.') + 3, std::string::npos);
    std::string bs = std::to_string(b);
    bs.erase(bs.find_first_of('.') + 3, std::string::npos);
    std::string cs = std::to_string(c);
    cs.erase(cs.find_first_of('.') + 3, std::string::npos);

    return as + "x^4 + " + bs + "x^2 + " + cs + " = 0";
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

size_t BiQuadraticEquation::degree() const
{
    // helps to define type of ane equation from BaseEquation class
    // could use enum {  Linear Quadratic BuQuadratic } but degree() also works fine.
    return 4;
}

std::unique_ptr<BaseEquation> BiQuadraticEquation::clone()
{
    return std::make_unique<BiQuadraticEquation>(*this);
}