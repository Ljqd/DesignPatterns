#include <iostream>

#include "src/LineWithLongestWordObserver.h"
#include "src/LongestLineObserver.h"
#include "src/LongestWordObserver.h"
#include "src/WordCountObserver.h"

#include "src/TextFileReader.h"

int main()
{
    TextFileReader reader = {};
    LineWithLongestWordObserver longestWordLineObserver = {};
    LongestLineObserver longestLineObserver = {};
    LongestWordObserver longestWordObserver = {};
    WordCountObserver wordCountObserver = {};

    reader.addObserver(&longestLineObserver);
    reader.addObserver(&longestWordObserver);
    reader.addObserver(&wordCountObserver);
    reader.addObserver(&longestWordLineObserver);

    reader.readFile("New Text Document.txt");

    std::cout << "longestWordLineObserver: " << longestWordLineObserver.getLongestWordLine() << std::endl;
    std::cout << "longestLineObserver: " << longestLineObserver.getLongestLine() << std::endl;
    std::cout << "longestWordObserver: " << longestWordObserver.getLongestWord() << std::endl;
    std::cout << "wordCountObserver: " << wordCountObserver.getWordCount() << std::endl;
}