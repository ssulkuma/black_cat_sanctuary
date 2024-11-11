//
//  Audio.h
//  Black Cat Sanctuary
//
//  Created by Sarita Sulkumäki on 11.11.2024.
//

#pragma once

#include "Game.h"

class Audio
{
public:
    // Sound Effects
    sf::SoundBuffer soundBuffer;

    // Constructor and destructor
    Audio();
    ~Audio();

    // Background music functions
    bool        playMusic();
    void        stopMusic();

    //Sound effect functions
    bool        loadSound(const std::string& sound, const std::string& filename);
    void        playSound(const std::string& sound);

private:
    // Music 
    sf::Music   background_music;
};