#include "LinearEquationCreator.h"

std::unique_ptr<BaseEquation> LinearEquationCreator::getEquation(const std::vector<float>& coefficient)
{
    return std::make_unique<LinearEquation>(coefficient);
}