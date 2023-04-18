#pragma once

#include <fstream>
#include <iostream>
#include <string>

class Editor {
public:

    static Editor* getInstance();

    void openForRead(const std::string& filename);
    void openForWrite(const std::string& filename);
    void close();

    std::string readLine();
    std::string getContent();
    void writeFile(const std::string& content);

private:
    Editor();

    static Editor* editor;
    std::ifstream iFile;
    std::ofstream oFile;
};