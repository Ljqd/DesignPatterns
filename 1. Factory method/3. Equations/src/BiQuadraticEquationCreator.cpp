#include "BiQuadraticEquationCreator.h"

std::unique_ptr<BaseEquation> BiQuadraticEquationCreator::getEquation(const std::vector<float>& coefficient)
{
    float a, b, c;
    a = coefficient[4]; b = coefficient[2]; c = coefficient[0];
    return std::make_unique<BiQuadraticEquation>(a, b, c);
}