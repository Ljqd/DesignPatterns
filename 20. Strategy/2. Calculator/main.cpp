#include <iostream>

#include "src/Calculator.h"
#include "src/AdditionStrategy.h"
#include "src/SubtractionStrategy.h"
#include "src/MultiplicationStrategy.h"
#include "src/DivisionStrategy.h"

int main()
{
    AdditionStrategy additionStrategy = {};
    SubtractionStrategy subtractionStrategy = {};
    MultiplicationStrategy multiplicationStrategy = {};
    DivisionStrategy divisionStrategy = {};

    Calculator calculator = {};

    calculator.setStrategy(&additionStrategy);
    std::cout << "a + b " << calculator.calculate(15, 5) << std::endl;

    calculator.setStrategy(&subtractionStrategy);
    std::cout << "a - b " << calculator.calculate(15, 5) << std::endl;

    calculator.setStrategy(&multiplicationStrategy);
    std::cout << "a * b " << calculator.calculate(15, 5) << std::endl;

    calculator.setStrategy(&divisionStrategy);
    std::cout << "a / b " << calculator.calculate(15, 5) << std::endl;

    std::cout << "Hello World!\n";
}