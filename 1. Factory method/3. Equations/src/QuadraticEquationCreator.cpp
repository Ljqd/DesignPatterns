#include "QuadraticEquationCreator.h"

std::unique_ptr<BaseEquation> QuadraticEquationCreator::getEquation(const std::vector<float>& coefficient)
{
    // [0, 1, 2, 3, 4] -> [0, 1, 2]
    return std::make_unique<QuadraticEquation>(coefficient);
}