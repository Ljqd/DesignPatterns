#pragma once

#include <string>
#include <iostream>

#include "MediaPlayer.h"
#include "MediaPlayerState.h"

class PausedState : public MediaPlayerState {
public:
    PausedState(MediaPlayer* player);

    void play() override;

    void pause() override;

    void next() override;

    void prev() override;

    void stop() override;

protected:
    MediaPlayer* player;
};