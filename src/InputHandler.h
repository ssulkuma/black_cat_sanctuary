//
//  InputHandler.h
//  Black Cat Sanctuary
//
//  Created by Sarita Sulkumäki on 11.11.2024.
//

#pragma once

#include "Game.h"

class Game;

class Input
{
public:
    // Constructor and destructor
    Input();
    ~Input();

    // Spell data
    sf::Clock   spellClock;

    // Input functions
    void    handleKeyPress(Game& game);

private:
};

// #include <SFML/Window/Keyboard.hpp>

// class Player;
// class Game;

// struct InputData
// {
//     bool m_movingUp = false;
//     bool m_movingDown = false;
//     bool m_movingLeft = false;
//     bool m_movingRight = false;
//     bool m_space = false;
//     bool m_spaceReleased = true;

//     bool hasInputs() { return m_movingUp || m_movingDown || m_movingLeft || m_movingRight || m_space;}
// };

// class GameInput
// {
// public:
//     GameInput(Game* pGame, Player* pPlayer);
//     ~GameInput();
    
//     void update(float deltaTime);
//     void onKeyPressed(sf::Keyboard::Key key);
//     void onKeyReleased(sf::Keyboard::Key key);
    
    
// private:
//     InputData m_inputData;
//     Game* m_pGame;
//     Player* m_pPlayer;
// };
