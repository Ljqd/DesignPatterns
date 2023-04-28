#pragma once

#include <iostream>

class Document
{
public:
    void create() {
        std::cout << "Document created" << std::endl;
    }
    void save() {
        std::cout << "Document saved" << std::endl;
    }
    void print() {
        std::cout << "Document printed" << std::endl;
    }
};