#include <iostream>
#include <string>

#include "src/FileHandler.h"
#include "src/AbstractFileHandler.h"
#include "src/ExcelHandler.h"
#include "src/JsonHandler.h"
#include "src/CsvHandler.h"

int main()
{
    FileHandler* excelHandler = new ExcelHandler();
    FileHandler* jsonHandler = new JsonHandler();
    FileHandler* csvHandler = new CsvHandler();

    AbstractFileHandler fileHandler = {};
    fileHandler.setNext(excelHandler);
    excelHandler->setNext(jsonHandler);
    jsonHandler->setNext(csvHandler);

    std::string path1 = "filename.json";
    std::string path2 = "filename.csv";
    std::string path3 = "filename.excel";
    std::string path4 = "filename.cpp";

    std::cout << path1 << '\n';
    fileHandler.open(path1);
    std::cout << '\n';

    std::cout << path2 << '\n';
    fileHandler.open(path2);
    std::cout << '\n';

    std::cout << path3 << '\n';
    fileHandler.open(path3);
    std::cout << '\n';

    std::cout << path4 << '\n';
    fileHandler.open(path4);
    std::cout << '\n';
}
