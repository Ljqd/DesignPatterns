#pragma once

#include <fstream>
#include <vector>

#include "Observer.h"

class TextFileReader {
private:
    std::vector<Observer*> observers;
public:
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify(const std::string& line) {
        for (Observer* observer : observers) {
            observer->update(line);
        }
    }

    void readFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Could not open file");
        }

        std::string line;
        while (std::getline(file, line)) {
            notify(line);
        }

        file.close();
    }
};