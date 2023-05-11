#pragma once

#include <string>
#include <sstream>

#include "Observer.h"

class WordCountObserver : public Observer {
private:
    int wordCount = 0;
public:
    void update(const std::string& line) override {
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            wordCount++;
        }
    }

    int getWordCount() const {
        return wordCount;
    }
};