#pragma once

#include <string>

class MediaPlayer;

class MediaPlayerState {
public:
    virtual void play() = 0;
    virtual void pause() = 0;
    virtual void next() = 0;
    virtual void prev() = 0;
    virtual void stop() = 0;
};