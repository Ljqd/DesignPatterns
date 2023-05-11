#pragma once

#include <vector>
#include "Triangle.h"

// make it template since we have NestedShanshot + EmptySnapshot + SecureSnapshot
template<typename Snapshot>
class Caretaker
{
public:
    // each Snapshot contains specific trianlge pointer (object)
    // so we need personal containers
    Caretaker(Triangle* obligator) : obligator(obligator) {}


    void save(Snapshot s) {
        // generally, we'll just call smt like:
        //     Snapshot s = obligator->getSnapshot()
        //     mementos.push_back(s)

        // but since we have 3 different implementations 
        // (normally it doesn't work this way, but I don't want to create 3 "different" identical caretakers;

        mementos.push_back(s);
    }

    void undo() {
        Snapshot last = mementos.back();
        mementos.pop_back();
        obligator->restore(last);
    }

private:
    Triangle* obligator;
    std::vector<Snapshot> mementos;
};