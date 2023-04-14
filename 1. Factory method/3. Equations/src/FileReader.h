#pragma once

#include <iostream>
#include <fstream>
#include <string>

class FileReader {
public:
    FileReader(const std::string& path);
    ~FileReader();

    std::string next();
    bool isEoF() const;

private:
    void readNextLine();

    std::ifstream file;
    std::string line;
};