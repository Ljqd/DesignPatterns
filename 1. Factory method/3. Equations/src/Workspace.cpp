#include "Workspace.h"


void Workspace::test_manually()
{
    test_linear();
    test_quadratic();
    test_biquadratic();
}

void Workspace::test_file(const std::string& path)
{

}

void Workspace::test_linear()
{
    LinearEquationCreator creator = {};

    std::unique_ptr<BaseEquation> equation; 
    std::vector<float> solutions1, solutions3, solutions2;

    std::cout << "test_linear:" << '\n';
    std::vector<float> linearCoefficents1 = { 2, 3 };
    std::vector<float> linearCoefficents2 = { 3, 0 };
    std::vector<float> linearCoefficents3 = { 2, 3, 999, 999, 999 }; // creator not obeys to check

    equation = creator.getEquation(linearCoefficents1);
    solutions1 = equation->solve();
    std::vector<float> temp1 = { -2.0 / 3.0 };
    std::cout << "\t1. " << equation->getEquationAsString() << '\n';

    equation = creator.getEquation(linearCoefficents2);
    solutions2 = equation->solve();
    std::vector<float> temp2 = { };
    std::cout << "\t2. " << equation->getEquationAsString() << '\n';


    equation = creator.getEquation(linearCoefficents3);
    solutions3 = equation->solve();
    std::vector<float> temp3 = { -2.0 / 3.0 };
    std::cout << "\t3. " << equation->getEquationAsString() << '\n';

    assert(std::equal(solutions1.begin(), solutions1.end(), temp1.begin()));
    assert(std::equal(solutions2.begin(), solutions2.end(), temp2.begin()));
    assert(std::equal(solutions3.begin(), solutions3.end(), temp3.begin()));

}

void Workspace::test_quadratic()
{
    QuadraticEquationCreator creator = {};

    std::unique_ptr<BaseEquation> equation;
    std::vector<float> solutions1, solutions2, solutions3;

    // since we plan to work with string of 2-3-5 elements,
    // we manually set quadratic as vector.size=3

    // also, we don't check all configurations,
    // just to see - does it actually works

    std::cout << "test_quadratic:" << '\n';
    std::vector<float> quadraticCoefficents1 = { 1, 2, 3 };
    std::vector<float> quadraticCoefficents2 = { -27, 0, 3 };
    std::vector<float> quadraticCoefficents3 = { 0, 2, 1 };

    equation = creator.getEquation(quadraticCoefficents1);
    solutions1 = equation->solve();
    std::vector<float> temp1 = { };
    std::cout << "\t1. " << equation->getEquationAsString() << '\n';

    equation = creator.getEquation(quadraticCoefficents2);
    solutions2 = equation->solve();
    std::vector<float> temp2 = { -3.0, 3.0, };
    std::cout << "\t2. " << equation->getEquationAsString() << '\n';

    equation = creator.getEquation(quadraticCoefficents3);
    solutions3 = equation->solve();
    std::vector<float> temp3 = { -2, 0 };
    std::cout << "\t3. " << equation->getEquationAsString() << '\n';

    assert(std::equal(solutions1.begin(), solutions1.end(), temp1.begin()));
    assert(std::equal(solutions2.begin(), solutions2.end(), temp2.begin()));
    assert(std::equal(solutions3.begin(), solutions3.end(), temp3.begin()));
}

void Workspace::test_biquadratic()
{
    BiQuadraticEquationCreator creator = {};

    std::unique_ptr<BaseEquation> equation;
    std::vector<float> solutions1, solutions2, solutions3;

    std::cout << "test_biquadratic:" << '\n';
    std::vector<float> quadraticCoefficents1 = { 4, 0, -5, 0, 1 };
    std::vector<float> quadraticCoefficents2 = { 0, 0, -1, 0, 1 };
    std::vector<float> quadraticCoefficents3 = { -1, 0, 0, 0, 1 };

    equation = creator.getEquation(quadraticCoefficents1);
    solutions1 = equation->solve();
    std::vector<float> temp1 = { -2.0, -1.0, 1.0, 2.0 };
    std::cout << "\t1. " << equation->getEquationAsString() << '\n';

    equation = creator.getEquation(quadraticCoefficents2);
    solutions2 = equation->solve();
    std::vector<float> temp2 = { -1.0, 0.0, 1.0 };
    std::cout << "\t2. " << equation->getEquationAsString() << '\n';

    equation = creator.getEquation(quadraticCoefficents3);
    solutions3 = equation->solve();
    std::vector<float> temp3 = { -1.0, 1.0 };
    std::cout << "\t3. " << equation->getEquationAsString() << '\n';

    assert(std::equal(solutions1.begin(), solutions1.end(), temp1.begin()));
    assert(std::equal(solutions2.begin(), solutions2.end(), temp2.begin()));
    assert(std::equal(solutions3.begin(), solutions3.end(), temp3.begin()));
}