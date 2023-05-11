#include "PausedState.h"
#include "PlayingState.h"
#include "StoppedState.h"

PausedState::PausedState(MediaPlayer* player)
{
    this->player = player;
}

void PausedState::play()
{
    std::cout << "Resuming " << player->getCurrentTrack() << std::endl;
    player->setState(new PlayingState(player));
}

void PausedState::pause()
{
    // Do nothing if already paused
    std::cout << "Already paused " << player->getCurrentTrack() << std::endl;
}

void PausedState::next()
{
    // Do nothing if paused
    std::cout << "Cannot go to next. Player is paused." << std::endl;
}

void PausedState::prev()
{
    // Do nothing if paused
    std::cout << "Cannot go to previous. Player is paused." << std::endl;
}

void PausedState::stop()
{
    std::cout << "Stopping player" << std::endl;
    player->setState(new StoppedState(player));
}