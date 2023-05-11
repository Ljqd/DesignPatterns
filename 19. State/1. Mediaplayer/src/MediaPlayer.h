#pragma once

#include <string>

#include "MediaPlayerState.h"
#include "PausedState.h"
#include "PlayingState.h"


class MediaPlayer {
private:
    MediaPlayerState* state;
    PlayingState playingState;
    PausedState pausedState;
public:
    MediaPlayer() {
        playingState = {};
        pausedState = {};
        state = &pausedState;
    }

    void setState(MediaPlayerState* state) {
        this->state = state;
    }

    std::string getIcon() {
        return state->getIcon();
    }

    void play() {
        state->play();
        setState(&playingState);
    }

    void pause() {
        state->pause();
        setState(&pausedState);
    }
};