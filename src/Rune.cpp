//
//  Rune.cpp
//  Black Cat Sanctuary
//
//  Created by Sarita Sulkumäki on 11.11.2024.
//

#include "Game.h"

// Constructor
Rune::Rune()
{
    rune_index = 0;
}

// Destructor
Rune::~Rune()
{

}

// Generates a random puzzle sequenze
void    Rune::generateRandomSequence()
{
    for (int i = 0; i < NUM_RUNES; ++i)
        rune_sequence.push_back(rand() % NUM_RUNES + 1);
}

// Compares player sequence with the generated puzzle sequence
bool    Rune::checkPlayerSequence(int rune_index)
{
    if (rune_sequence[rune_index] != player_sequence[rune_index])
        return (false);
    return (true);
}

// Rune animations
void    Rune::animateRunes(int rune_index, std::vector<sf::Sprite>& runes, sf::RenderWindow& window, float deltatime, float& animationTimer)
{
    int         current_frame;
    sf::IntRect frame_rect;
    
    current_frame = static_cast<int>(animationTimer / FRAME_DURATION) % FRAME_COUNT;
    frame_rect.height = 400;
    frame_rect.width = 400;
    frame_rect.top = 0;
    frame_rect.left = 0;
    runes[rune_index].setTextureRect(frame_rect);
    
    window.clear();
    window.draw(runes[rune_index]);
    window.display();

    animationTimer += deltatime;
    if (animationTimer >= FRAME_COUNT * FRAME_DURATION * 2)
        animationTimer = 0;

}

// Plays the rune sequence
void    Rune::playSequence(std::vector<sf::Sprite>& runes, sf::RenderWindow& window, float deltatime)
{
    float animation_timer;

    animation_timer = 0;
    for (int rune : rune_sequence)
    {
        animateRunes(rune - 1, runes, window, deltatime, animation_timer);
        sf::sleep(sf::seconds(ANIMATION_TIME));
    }
}