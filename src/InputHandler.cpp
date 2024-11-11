//
//  InputHandler.cpp
//  Black Cat Sanctuary
//
//  Created by Sarita Sulkumäki on 11.11.2024.
//

#include "Game.h"

//Constructor
Input::Input()
{

}

// Destructor
Input::~Input()
{

}

// Handles key press input
void    Input::handleKeyPress(Game& game)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && game.player.body.getPosition().y > 0)
    {
        game.player.body.move(0.0f, -PLAYER_SPEED * game.deltatime.asSeconds());
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && game.player.body.getPosition().y < (WINDOW_HEIGHT - PLAYER_HEIGHT))
    {
        game.player.body.move(0.0f, PLAYER_SPEED * game.deltatime.asSeconds());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        if (spellClock.getElapsedTime().asSeconds() >= SPELL_COOLDOWN)
        {
            Star    star;
            star.initializeStars(game.player.body.getPosition());
            star.star_projectile.setTexture(game.star_tex);
            star.star_projectile.setScale(0.02f, 0.02f);
            game.stars.push_back(star);
            spellClock.restart();
        }
    }
    for (auto& star : game.stars)
        star.updateStars(game.deltatime.asSeconds(), game.stars);
}



// GameInput::GameInput(Game* pGame, Player* pPlayer) :
//     m_pGame(pGame), m_pPlayer(pPlayer)
// {

    
// }

// GameInput::~GameInput()
// {
    
// }

// void GameInput::update(float deltaTime)
// {
//     if (m_inputData.hasInputs())
//     {
//         m_pPlayer->move(m_inputData, deltaTime);
//     }

//     if (m_inputData.m_space)
//     {
//         m_pPlayer->attack();
//     }
// }

// void GameInput::onKeyPressed(sf::Keyboard::Key key)
// {
//     if (key == sf::Keyboard::Up)
//     {
//         m_inputData.m_movingUp = true;
//     }
//     else if (key == sf::Keyboard::Down)
//     {
//         m_inputData.m_movingDown = true;
//     }
//     else if (key == sf::Keyboard::Left)
//     {
//         m_inputData.m_movingLeft = true;
//     }
//     else if (key == sf::Keyboard::Right)
//     {
//         m_inputData.m_movingRight = true;
//     }
//     else if (key == sf::Keyboard::Space)
//     {
//         if (m_inputData.m_spaceReleased)
//         {
//             m_inputData.m_space = true;
//         }
//         m_inputData.m_spaceReleased = false;
//     }
// }

// void GameInput::onKeyReleased(sf::Keyboard::Key key)
// {
//     if (key == sf::Keyboard::Up)
//     {
//         m_inputData.m_movingUp = false;
//     }
//     else if (key == sf::Keyboard::Down)
//     {
//         m_inputData.m_movingDown = false;
//     }
//     else if (key == sf::Keyboard::Left)
//     {
//         m_inputData.m_movingLeft = false;
//     }
//     else if (key == sf::Keyboard::Right)
//     {
//         m_inputData.m_movingRight = false;
//     }
//     else if (key == sf::Keyboard::Space)
//     {
//         m_inputData.m_space = false;
//         m_inputData.m_spaceReleased = true;
//     }
// }
