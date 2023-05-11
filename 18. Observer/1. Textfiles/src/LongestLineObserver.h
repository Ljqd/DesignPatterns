#pragma once

#include <string>

#include "Observer.h"

class LongestLineObserver : public Observer {
private:
    std::string longestLine;
public:
    void update(const std::string& line) override {
        if (line.size() > longestLine.size()) {
            longestLine = line;
        }
    }

    std::string getLongestLine() const {
        return longestLine;
    }
};