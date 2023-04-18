#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class FileWriter {

    static const std::string pathTo1;
    static const std::string pathTo2;
    static const std::string pathTo3;
    static const std::string pathTo4;
    static const std::string pathToInf;
    static const std::string pathToEmpty;

public:

    void addEmpty(const std::string& equation);
    void addOne(const std::string& equation, const std::vector<float>& solutions);
    void addTwo(const std::string& equation, const std::vector<float>& solutions);
    void addThree(const std::string& equation, const std::vector<float>& solutions);
    void addFour(const std::string& equation, const std::vector<float>& solutions);
    void addInf(const std::string& equation, const std::vector<float>& solutions);

private:
    void addToFile(const std::string& path, const std::string& equation, const std::vector<float>& solutions);

    std::ifstream file;
    std::string line;
};