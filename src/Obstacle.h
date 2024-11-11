//
//  Obstacle.h
//  Black Cat Sanctuary
//
//  Created by Sarita Sulkumäki on 11.11.2024.
//

#pragma once

#include "Game.h"

enum obstacleType
{
    WALL,
    ENEMY,
    CAT,
    DOOR
};

class Obstacle
{
public:
    // Obstacle data
    sf::Sprite      obstacle_sprite;
    float           position_y;
    float           movement_speed;
    int             type;
    bool            hit;

    // Timers
    sf::Clock       spawnTime;
    sf::Clock       hitCooldown;

    // Constructor and destructor
    Obstacle();
    ~Obstacle();

    // Obstacle functions
    void    updateObstacle(float deltatime, std::vector<Obstacle>&   obstacles);
    void    spawnObstacle(std::vector<Obstacle>&   obstacles, int& spawn_count);


    void    checkStarCollision(int type);

private:

};