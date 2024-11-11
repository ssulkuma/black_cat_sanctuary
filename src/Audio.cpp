//
//  Audio.cpp
//  Black Cat Sanctuary
//
//  Created by Sarita Sulkumäki on 11.11.2024.
//

#include "Game.h"

// Constructor
Audio::Audio()
{
    background_music.setLoop(true);
    background_music.setVolume(50.f);
}

// Destructor
Audio::~Audio()
{

}

// Plays background music
void   Audio::playMusic()
{
    background_music.play();
} 

// Stops bakcground music
void    Audio::stopMusic()
{
    background_music.stop();
}

// Loads sound effect into a sound buffer
bool    Audio::loadSound(const std::string& sound, const std::string& filename)
{
    return (true);
}

// Plays sound effect
void    Audio::playSound(const std::string& sound)
{

}