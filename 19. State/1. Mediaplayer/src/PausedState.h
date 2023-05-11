#pragma once

#include <string>
#include <iostream>
#include "MediaPlayerState.h"

class PausedState : public MediaPlayerState {
public:
    std::string getIcon() override {
        return "play button";
    }

    void play() override {
        std::cout << "Video playing, icon set to pause button" << std::endl;
    }

    void pause() override {
        // do nothing
    }
};