#pragma once

#include <sstream>
#include <string>
#include <vector>

#include "Observer.h"


class LineWithLongestWordObserver : public Observer {
private:
    std::string longestWordLine;
    std::string longestWord;
public:
    void update(const std::string& line) override {
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            if (word.size() > longestWord.size()) {
                longestWord = word;
                longestWordLine = line;
            }
        }
    }

    std::string getLongestWordLine() const {
        return longestWordLine;
    }
};