#pragma once

#include <string>
#include <iostream>

#include "MediaPlayer.h"
#include "MediaPlayerState.h"

class StoppedState : public MediaPlayerState {
public:
    StoppedState(MediaPlayer* player);

    void play() override;

    void pause() override;

    void next() override;

    void prev() override;

    void stop() override;

protected:
    MediaPlayer* player;

};