#include <iostream>

#include "src/MediaPlayer.h"


int main()
{
    MediaPlayer mediaPlayer = {};

    mediaPlayer.addTrack("Iron maiden - Fear of the dark");
    mediaPlayer.addTrack("Nickleback - Lullaby");
    mediaPlayer.addTrack("Linkin Park - Numb");
    mediaPlayer.addTrack("Philip Wesley - Racing Against the Sunset");


    mediaPlayer.play();
    mediaPlayer.next();
    mediaPlayer.pause();
    mediaPlayer.next();
    mediaPlayer.pause();
    mediaPlayer.play();
    mediaPlayer.prev();
    mediaPlayer.play();
    mediaPlayer.stop();
}