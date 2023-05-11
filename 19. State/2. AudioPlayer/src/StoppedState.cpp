#include "StoppedState.h"
#include "PlayingState.h"
#include "PausedState.h"


StoppedState::StoppedState(MediaPlayer* player) 
{
    this->player = player;
}

void StoppedState::play() 
{
    std::cout << "Starting " << player->getCurrentTrack() << std::endl;
    player->setState(new PlayingState(player));
}

void StoppedState::pause() 
{
    // Do nothing if stopped
    std::cout << "Cannot pause. Player is stopped." << std::endl;
}

void StoppedState::next() 
{
    // Do nothing if stopped
    std::cout << "Cannot go to next. Player is stopped." << std::endl;
}

void StoppedState::prev() 
{
    // Do nothing if stopped
    std::cout << "Cannot go to previous. Player is stopped." << std::endl;
}

void StoppedState::stop() 
{
    // Do nothing if already stopped
    std::cout << "Already stopped." << std::endl;
}
    