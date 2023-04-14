#include "Workspace.h"


void Workspace::test_manually()
{
    test_linear();
    test_quadratic();
    test_biquadratic();
}

void Workspace::test_file(const std::string& path)
{
    try {
        FileReader reader(path);
        FileWriter writer = {};

        std::cout << "Path: " << path << '\n';

        while (!reader.isEoF()) {
            std::string line = reader.next();
            std::vector<float> coefficients = getCoefficients(line);
            std::unique_ptr<BaseEquation> equation = getEquation(coefficients);
            std::vector<float> solutions = equation->solve();

            if (solutions.size() == 0)
                writer.addEmpty(equation->getEquationAsString());
            else if (solutions.size() == 2)
                writer.addTwo(equation->getEquationAsString(), solutions);
            else if (solutions.size() == 3)
                writer.addThree(equation->getEquationAsString(), solutions);
            else if (solutions.size() == 4)
                writer.addFour(equation->getEquationAsString(), solutions);
            else if (solutions[0] != INFINITY)
                writer.addOne(equation->getEquationAsString(), solutions);
            else
                writer.addInf(equation->getEquationAsString(), solutions);
        }
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void Workspace::test_linear()
{
    std::unique_ptr<BaseEquationCreator> creator = std::make_unique<LinearEquationCreator>();

    std::unique_ptr<BaseEquation> equation; 
    std::vector<float> solutions1, solutions3, solutions2;

    std::cout << "test_linear:" << '\n';
    std::vector<float> linearCoefficents1 = { 2, 3 };
    std::vector<float> linearCoefficents2 = { 3, 0 };
    std::vector<float> linearCoefficents3 = { 2, 3, 999, 999, 999 }; // creator not obeys to check

    equation = creator->getEquation(linearCoefficents1);
    solutions1 = equation->solve();
    std::vector<float> temp1 = { -2.0 / 3.0 };
    std::cout << "\t1. " << equation->getEquationAsString() << '\n';

    equation = creator->getEquation(linearCoefficents2);
    solutions2 = equation->solve();
    std::vector<float> temp2 = { };
    std::cout << "\t2. " << equation->getEquationAsString() << '\n';


    equation = creator->getEquation(linearCoefficents3);
    solutions3 = equation->solve();
    std::vector<float> temp3 = { -2.0 / 3.0 };
    std::cout << "\t3. " << equation->getEquationAsString() << '\n';

    assert(std::equal(solutions1.begin(), solutions1.end(), temp1.begin()));
    assert(std::equal(solutions2.begin(), solutions2.end(), temp2.begin()));
    assert(std::equal(solutions3.begin(), solutions3.end(), temp3.begin()));

}

void Workspace::test_quadratic()
{
    std::unique_ptr<BaseEquationCreator> creator = std::make_unique<QuadraticEquationCreator>();

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

    equation = creator->getEquation(quadraticCoefficents1);
    solutions1 = equation->solve();
    std::vector<float> temp1 = { };
    std::cout << "\t1. " << equation->getEquationAsString() << '\n';

    equation = creator->getEquation(quadraticCoefficents2);
    solutions2 = equation->solve();
    std::vector<float> temp2 = { -3.0, 3.0, };
    std::cout << "\t2. " << equation->getEquationAsString() << '\n';

    equation = creator->getEquation(quadraticCoefficents3);
    solutions3 = equation->solve();
    std::vector<float> temp3 = { -2, 0 };
    std::cout << "\t3. " << equation->getEquationAsString() << '\n';

    assert(std::equal(solutions1.begin(), solutions1.end(), temp1.begin()));
    assert(std::equal(solutions2.begin(), solutions2.end(), temp2.begin()));
    assert(std::equal(solutions3.begin(), solutions3.end(), temp3.begin()));
}

void Workspace::test_biquadratic()
{
    std::unique_ptr<BaseEquationCreator> creator = std::make_unique<BiQuadraticEquationCreator>();

    std::unique_ptr<BaseEquation> equation;
    std::vector<float> solutions1, solutions2, solutions3;

    std::cout << "test_biquadratic:" << '\n';
    std::vector<float> quadraticCoefficents1 = { 4, 0, -5, 0, 1 };
    std::vector<float> quadraticCoefficents2 = { 0, 0, -1, 0, 1 };
    std::vector<float> quadraticCoefficents3 = { -1, 0, 0, 0, 1 };

    equation = creator->getEquation(quadraticCoefficents1);
    solutions1 = equation->solve();
    std::vector<float> temp1 = { -2.0, -1.0, 1.0, 2.0 };
    std::cout << "\t1. " << equation->getEquationAsString() << '\n';

    equation = creator->getEquation(quadraticCoefficents2);
    solutions2 = equation->solve();
    std::vector<float> temp2 = { -1.0, 0.0, 1.0 };
    std::cout << "\t2. " << equation->getEquationAsString() << '\n';

    equation = creator->getEquation(quadraticCoefficents3);
    solutions3 = equation->solve();
    std::vector<float> temp3 = { -1.0, 1.0 };
    std::cout << "\t3. " << equation->getEquationAsString() << '\n';

    assert(std::equal(solutions1.begin(), solutions1.end(), temp1.begin()));
    assert(std::equal(solutions2.begin(), solutions2.end(), temp2.begin()));
    assert(std::equal(solutions3.begin(), solutions3.end(), temp3.begin()));
}

std::vector<float> Workspace::getCoefficients(std::string& line)
{
    std::vector<float> result;
    std::stringstream ss(line);
    float value;

    while (ss >> value) {
        result.push_back(value);
    }

    return result;
}

std::unique_ptr<BaseEquation> Workspace::getEquation(std::vector<float>& coefficients)
{
    std::unique_ptr<BaseEquationCreator> creator = nullptr;
    if (coefficients.size() == 2)
    {
        creator = std::make_unique<LinearEquationCreator>();
    }
    else if (coefficients.size() == 3)
    {
        creator = std::make_unique<QuadraticEquationCreator>();
    }
    else if (coefficients.size() == 5)
    {
        creator = std::make_unique<BiQuadraticEquationCreator>();
    }
    else
    {
        throw("Workspace: getEquation(), unknown coefficients.size()");
    }
    return creator->getEquation(coefficients);
}