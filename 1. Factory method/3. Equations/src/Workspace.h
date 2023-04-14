#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

#include "BaseEquation.h"
#include "FileReader.h"
#include "LinearEquationCreator.h"
#include "QuadraticEquationCreator.h"
#include "BiQuadraticEquationCreator.h"


class Workspace
{
public:
    void test_manually();
    void test_file(const std::string& path);

private:
    void test_linear();
    void test_quadratic();
    void test_biquadratic();
};