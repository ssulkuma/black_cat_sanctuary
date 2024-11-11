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

}

// Destructor
Audio::~Audio()
{

}

// Plays background music
bool   Audio::playMusic()
{
    return (true);
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