#include <iostream>

#include "src/CalculatorHandler.h"
#include "src/AbstractCalculatorHandler.h"
#include "src/AdditionHandler.h"
#include "src/DivisionHandler.h"
#include "src/MultiplicationHandler.h"
#include "src/SubstractionHandler.h"

int main()
{
    AbstractCalculatorHandler calculator = {};

    AdditionHandler* addition = new AdditionHandler();
    DivisionHandler* division = new DivisionHandler();
    MultiplicationHandler* multiplication = new MultiplicationHandler();
    SubstractionHandler* substraction = new SubstractionHandler();

    addition->setNext(substraction);
    substraction->setNext(multiplication);
    multiplication->setNext(division);

    calculator.setNext(addition);

    std::string input1 = "2 + 2";
    std::string input2 = "3 - 2";
    std::string input3 = "4 * 4";
    std::string input4 = "10 / 2";
    std::string input5 = "1 ? 2";

    float answer = 0;

    std::cout << '\t' + input1 << '\n';
    answer = calculator.evaluate(input1);
    std::cout << std::to_string(answer) << '\n';

    std::cout << '\t' + input2 << '\n';
    answer = calculator.evaluate(input2);
    std::cout << std::to_string(answer) << '\n';

    std::cout << '\t' + input3 << '\n';
    answer = calculator.evaluate(input3);
    std::cout << std::to_string(answer) << '\n';

    std::cout << '\t' + input4 << '\n';
    answer = calculator.evaluate(input4);
    std::cout << std::to_string(answer) << '\n';

    std::cout << '\t' + input5 << '\n';
    answer = calculator.evaluate(input5);
    std::cout << std::to_string(answer) << '\n';
}