#pragma once

#include <string>
#include <sstream>

#include "Observer.h"


class LongestWordObserver : public Observer {
private:
    std::string longestWord;
public:
    void update(const std::string& line) override {
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            if (word.size() > longestWord.size()) {
                longestWord = word;
            }
        }
    }

    std::string getLongestWord() const {
        return longestWord;
    }
};