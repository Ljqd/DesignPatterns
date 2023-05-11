#include "MediaPlayer.h"
#include "PausedState.h"

MediaPlayer::MediaPlayer()
{
    state = new PausedState(this);
    currentTrackNum = 0;
    tracks = {};
}

void MediaPlayer::setState(MediaPlayerState* newState)
{
    delete this->state;
    this->state = newState;
}

void MediaPlayer::addTrack(const std::string& track)
{
    tracks.push_back(track);
}

void MediaPlayer::setTrackNum(int trackNum)
{
    if (trackNum < 0 || trackNum >=tracks.size())
    {
        return;
    }
    this->currentTrackNum = trackNum;
}

int MediaPlayer::getCurrentTrackNum() const
{
    return currentTrackNum;
}

std::string MediaPlayer::getCurrentTrack() const
{
    return tracks[currentTrackNum];
}

std::vector<std::string> MediaPlayer::getTracks() const
{
    return tracks;
}

void MediaPlayer::play()
{
    if (state) state->play();
}

void MediaPlayer::pause()
{
    if (state) state->pause();
}

void MediaPlayer::next()
{
    if (state) state->next();
}

void MediaPlayer::prev()
{
    if (state) state->prev();
}

void MediaPlayer::stop()
{
    if (state) state->stop();
}