//
//  Player.cpp
//  Black Cat Sanctuary
//
//  Created by Sarita Sulkumäki on 11.11.2024.
//

#include "Game.h"

// Constructor
Player::Player()
{
    body.setPosition(50.0f, WINDOW_HEIGHT / 2 - PLAYER_HEIGHT / 2);
    body.setScale(0.25f, 0.25f);
}

// Destructor
Player::~Player()
{

}

// Checks player collision with the obstacles
void    Player::checkPlayerCollision(Obstacle&   obstacle, int& score, int& game_state)
{
    if (!obstacle.hit)
    {
        obstacle.hit = true;
        switch (obstacle.type) {
            case WALL:
            case ENEMY:
                score--;
                if (score <= 0)
                    game_state = GAMESTATE_GAMEOVER;
                break;
            case CAT:
                score++;
                break;
            case DOOR:
                game_state = GAMESTATE_PUZZLE;
                break;
            default:
                break;
        }
    }
    if (obstacle.hit && obstacle.hitCooldown.getElapsedTime().asSeconds() <= 3.0f)
    {
        obstacle.hit = false;
        obstacle.hitCooldown.restart();
    }
}

// Updates player position
void    Player::updatePlayer(float direction, float deltatime)
{
    body.move(0.0f, direction * deltatime);
}

// #include "Player.h"
// #include "Weapon.h"
// #include "InputHandler.h"
// #include "Constants.h"
// #include <vector>
// #include "Game.h"

// Player::Player(Game* pGame) :
//     Rectangle(sf::Vector2f(PlayerWidth, PlayerHeight)),
//     m_pGame(pGame),
//     m_pWeapon(std::make_unique<Weapon>())
// {
//     setOrigin(sf::Vector2f(0.0f, 0.0f));
// }

// bool Player::initialise()
// {
//     m_sprite.setTexture(*m_pGame->getPlayerTexture());
//     m_sprite.setScale(3.5f, 3.5f);
//     setIsDead(false);
//     setPosition(ScreenWidth / 2, ScreenHeight / 2);
//     m_sprite.setPosition(getPosition());
//     return true;
// }

// void Player::move(InputData inputData, float deltaTime)
// {
//     float xSpeed = 0.0f;
//     float ySpeed = 0.0f;
    
//     xSpeed -= inputData.m_movingLeft * PlayerSpeed;
//     xSpeed += inputData.m_movingRight * PlayerSpeed;
//     xSpeed *= deltaTime;

//     ySpeed -= inputData.m_movingUp * PlayerSpeed;
//     ySpeed += inputData.m_movingDown * PlayerSpeed;
//     ySpeed *= deltaTime;
    
//     sf::Transformable::move(sf::Vector2f(xSpeed, ySpeed));
//     setPosition(std::clamp(getPosition().x, 0.0f, (float)ScreenWidth), getPosition().y);

//     if (m_pWeapon->isActive() == false)
//     {
//         if (inputData.m_movingLeft == true && inputData.m_movingRight == false)
//             m_direction = LEFT;
//         else if (inputData.m_movingLeft == false && inputData.m_movingRight == true)
//             m_direction = RIGHT;
//     }
// }

// void Player::attack()
// {
//     m_pWeapon->setActive(true);
// }

// void Player::update(float deltaTime)
// {
//     sf::Vector2f weaponSize = m_pWeapon->getSize();

//     m_sprite.setPosition(getPosition());
//     m_pWeapon->setPosition(sf::Vector2f(
//         getCenter().x - (m_direction == LEFT ? weaponSize.x : 0.0f),
//         getCenter().y - weaponSize.y / 2.0f));
//     m_pWeapon->update(deltaTime);
// }

// void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
// {
//     Rectangle::draw(target, states);
//     m_pWeapon->draw(target, states);
// }