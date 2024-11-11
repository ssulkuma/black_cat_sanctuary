//
//  Obstacle.cpp
//  Black Cat Sanctuary
//
//  Created by Sarita Sulkumäki on 11.11.2024.
//

#include "Game.h"

// Constructor
Obstacle::Obstacle()
{
    position_y = static_cast<float>(rand() % WINDOW_HEIGHT);
    obstacle_sprite.setPosition(WINDOW_WIDTH - 200.0f, position_y);
    movement_speed = 100.0f;
    type = 0;
    hit = false;
}

// Destructor
Obstacle::~Obstacle()
{

}

// Updates obstacle position 
void    Obstacle::updateObstacle(float deltatime, std::vector<Obstacle>&   obstacles)
{
    obstacle_sprite.move(-movement_speed * deltatime, 0.0f);
    obstacles.erase(std::remove_if(obstacles.begin(), obstacles.end(), [](const Obstacle& obstacle){
        return obstacle.obstacle_sprite.getPosition().x < 0.0f ||
        obstacle.hit;
    }), obstacles.end());
}

// Creates different type of obstacles in random y-positions on the right side of screen
void    Obstacle::spawnObstacle(Game& game)
{
    if (spawnTime.getElapsedTime().asSeconds() >= SPAWN_COOLDOWN && game.spawn_count < 20)
    {
        Obstacle    new_obstacle;
        int         random_type;
        
        if (game.spawn_count > 18)
            random_type = DOOR;
        else
            random_type = rand() % 3;
        switch (random_type) {
            case WALL:
                new_obstacle.obstacle_sprite.setTexture(game.wall_tex);
                new_obstacle.movement_speed = 100.0f;
                new_obstacle.obstacle_sprite.setScale(0.75f, 0.75f);
                new_obstacle.type = WALL;
                break;
            case ENEMY:
                new_obstacle.obstacle_sprite.setTexture(game.enemy_tex);
                new_obstacle.movement_speed = 150.0f;
                new_obstacle.obstacle_sprite.setScale(0.3f, 0.3f);
                new_obstacle.type = ENEMY;
                break;
            case CAT:
                new_obstacle.obstacle_sprite.setTexture(game.cat_tex);
                new_obstacle.movement_speed = 100.0f;
                new_obstacle.obstacle_sprite.setScale(0.15f, 0.15f);
                new_obstacle.type = CAT;
                break;
            case DOOR:
                new_obstacle.obstacle_sprite.setTexture(game.door_tex);
                new_obstacle.movement_speed = 80.0f;
                new_obstacle.obstacle_sprite.setPosition(new_obstacle.obstacle_sprite.getPosition().x, (WINDOW_HEIGHT / 2) - (new_obstacle.obstacle_sprite.getLocalBounds().height / 2));
                new_obstacle.obstacle_sprite.setScale(0.5f, 0.5f);
                new_obstacle.type = DOOR;
                break;
            default:
                break;
        }
        game.obstacles.push_back(new_obstacle);
        game.spawn_count++;
        spawnTime.restart();
    }
}