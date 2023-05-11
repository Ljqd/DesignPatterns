#pragma once

class OperationStrategy 
{
public:
    virtual double execute(double a, double b) const = 0;
};