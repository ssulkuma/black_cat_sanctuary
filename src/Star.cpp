//
//  Star.cpp
//  Black Cat Sanctuary
//
//  Created by Sarita Sulkumäki on 11.11.2024.
//

#include "Game.h"

// Constructor
Star::Star()
{
    hit = false;
}

// Destructor
Star::~Star()
{

}

// Initializes stars
void    Star::initializeStars(sf::Vector2f playerPosition)
{
    star_projectile.setPosition(playerPosition.x + PLAYER_WIDTH, playerPosition.y + PLAYER_HEIGHT);
}

// Updates star positions
void    Star::updateStars(float deltatime, std::vector<Star>&   stars)
{
    star_projectile.move(STAR_SPEED * deltatime, 0.0f);
    star_projectile.rotate(STAR_ROTATION_SPEED * deltatime);
    stars.erase(std::remove_if(stars.begin(), stars.end(), [](const Star& star){
        return star.star_projectile.getPosition().x > WINDOW_WIDTH ||
        star.hit;
    }), stars.end());
}

// Check star spell collision with obstacle
void    Star::checkStarCollision(Obstacle& obstacle, Star& star)
{
    switch (obstacle.type)
    {
    case WALL:
        star.hit = true;
        break;
    case ENEMY:
        star.hit = true;
        obstacle.hit = true;
        break;
    default:
        break;
    }
}