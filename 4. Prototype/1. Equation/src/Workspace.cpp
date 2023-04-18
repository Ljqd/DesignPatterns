#include "Workspace.h"

void Workspace::test_clone()
{
    std::unique_ptr<BaseEquationCreator> linearCreator = std::make_unique<LinearEquationCreator>();
    std::unique_ptr<BaseEquationCreator> quadraticCreator = std::make_unique<QuadraticEquationCreator>();
    std::unique_ptr<BaseEquationCreator> biquadraticCreator = std::make_unique<BiQuadraticEquationCreator>();
    
    std::vector<float> linearCoefficients = { 2, 3 };
    std::vector<float> quadraticCoefficients = { 1, 2, 3 };
    std::vector<float> biquadraticCoefficients = { 4, 0, -5, 0, 1 };


    std::unique_ptr<BaseEquation> linearEquation1 = linearCreator->getEquation(linearCoefficients);
    std::unique_ptr<BaseEquation> quadraticEquation1 = quadraticCreator->getEquation(quadraticCoefficients);
    std::unique_ptr<BaseEquation> biquadraticEquation1 = biquadraticCreator->getEquation(biquadraticCoefficients);

    // Polymorphism
    // we don't use copy constructor linearEquation2 = linearEquation1
    // we clone "unknown" equations
    std::unique_ptr<BaseEquation> linearEquation2 = linearEquation1->clone();
    std::unique_ptr<BaseEquation> quadraticEquation2 = quadraticEquation1->clone();
    std::unique_ptr<BaseEquation> biquadraticEquation2 = biquadraticEquation1->clone();

    assert(linearEquation1 != linearEquation2); // has different pointers
    assert(quadraticEquation1 != quadraticEquation2); 
    assert(biquadraticEquation1 != biquadraticEquation2);
}