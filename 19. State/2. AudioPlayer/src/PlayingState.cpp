#include "PlayingState.h"

#include "PausedState.h"
#include "StoppedState.h"


PlayingState::PlayingState(MediaPlayer* player) 
{
    this->player = player;
}

void PlayingState::play() 
{
    // Do nothing if already playing
    std::cout << "Already playing " << player->getCurrentTrack() << std::endl;
}

void PlayingState::pause() 
{
    std::cout << "Pausing " << player->getCurrentTrack() << std::endl;
    player->setState(new PausedState(player));
}

void PlayingState::next() 
{
    player->setTrackNum(player->getCurrentTrackNum() + 1);
    std::cout << "Playing next track: " << player->getCurrentTrack() << std::endl;
}

void PlayingState::prev() 
{
    player->setTrackNum(player->getCurrentTrackNum() - 1);
    std::cout << "Playing previous track: " << player->getCurrentTrack() << std::endl;
}

void PlayingState::stop() 
{
    std::cout << "Stopping player" << std::endl;
    player->setState(new StoppedState(player));
}