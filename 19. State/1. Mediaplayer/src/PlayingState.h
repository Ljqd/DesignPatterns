#pragma once

#include <string>
#include <iostream>
#include "MediaPlayerState.h"

class PlayingState : public MediaPlayerState {
public:
    std::string getIcon() override {
        return "pause button";
    }

    void play() override {
        // do nothing
    }

    void pause() override {
        std::cout << "Video paused, icon set to play button" << std::endl;
    }
};