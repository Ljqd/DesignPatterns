#pragma once

#include <string>
#include <vector>

#include "MediaPlayerState.h"
#include "PausedState.h"

class MediaPlayer {
public:
    MediaPlayer();

    void setState(MediaPlayerState* newState);

    void addTrack(const std::string& track);

    void setTrackNum(int trackNum);

    int getCurrentTrackNum() const;

    std::string getCurrentTrack() const;

    std::vector<std::string> getTracks() const;

    void play();

    void pause();

    void next();

    void prev();

    void stop();

private:
    std::vector<std::string> tracks;
    MediaPlayerState* state;
    int currentTrackNum = 0;
};