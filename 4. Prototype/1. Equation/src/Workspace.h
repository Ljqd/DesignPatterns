#pragma once

#include <iostream>
#include <vector>
#include <string> 
#include <sstream> // "1 2 3" line -> {1, 2, 3} vector
#include <memory> // unique_ptr
#include <algorithm> // sort(vector)
#include <cassert>

#include "BaseEquation.h"
#include "FileReader.h"
#include "FileWriter.h"
#include "LinearEquationCreator.h"
#include "QuadraticEquationCreator.h"
#include "BiQuadraticEquationCreator.h"


class Workspace
{
public:
    void test_manually();
    void test_file(const std::string& path);
    void test_clone();

private:
    void test_linear();
    void test_quadratic();
    void test_biquadratic();
    std::vector<float> getCoefficients(std::string& line);
    std::unique_ptr<BaseEquation> getEquation(std::vector<float>& coefficients);
};