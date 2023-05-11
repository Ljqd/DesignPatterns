#pragma once

#include <string>

class MediaPlayerState {
public:
    virtual std::string getIcon() = 0;
    virtual void play() = 0;
    virtual void pause() = 0;
    virtual ~MediaPlayerState() {}
};