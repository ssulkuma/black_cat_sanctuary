//
//  Rune.h
//  Black Cat Sanctuary
//
//  Created by Sarita Sulkumäki on 11.11.2024.
//

#pragma once

#include "Game.h"

class Rune
{
public:
    // Rune data
    sf::Sprite  rune;
    int         rune_index;

    // Constructor and destructor
    Rune();
    ~Rune();
    
    // Rune functions
    void    generateRandomSequence();
    bool    checkPlayerSequence(int rune_index);
    void    animateRunes(int rune_index, std::vector<sf::Sprite>& runes, sf::RenderWindow& window, float deltatime, float& animationTimer);
    void    playSequence(std::vector<sf::Sprite>& runes, sf::RenderWindow& window, float deltatime);

    // Vectors
    std::vector<int> rune_sequence;
    std::vector<int> player_sequence;
private:

    // Animation data
    // int         current_frame;
    // sf::IntRect frame_rect;
};