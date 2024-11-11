//
//  Player.h
//  Black Cat Sanctuary
//
//  Created by Sarita Sulkumäki on 11.11.2024.
//

#pragma once

#include "Game.h"

class Player
{
public:
    // Player data
    sf::Sprite  body;

    // Constructor and destructor
    Player();
    ~Player();

    // Player functions
    void    updatePlayer(float direction, float deltatime);
    void    checkPlayerCollision(Obstacle&   obstacle, int& score, int& game_state);

private:

};

// #include "Rectangle.h"

// #include <memory>

// struct InputData;

// class Game;
// class Weapon;

// enum eDirection
// {
//     LEFT,
//     RIGHT
// };

// class Player : public Rectangle
// {
// public:
//     Player(Game* pGame);
//     virtual ~Player() {}
    
//     bool initialise();
//     void move(InputData inputData, float deltaTime);
//     void attack();
//     void update(float deltaTime);
//     virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

//     bool isDead() const { return m_isDead; }
//     void setIsDead(bool isDead) { m_isDead = isDead; }

//     Weapon* getWeapon() { return m_pWeapon.get(); }

// private:
//     bool    m_isDead = false;
//     eDirection m_direction = LEFT;
//     Game*   m_pGame;
//     std::unique_ptr<Weapon> m_pWeapon;
// };
