//
//  Star.h
//  Black Cat Sanctuary
//
//  Created by Sarita Sulkumäki on 11.11.2024.
//

#pragma once

class Star
{
public:
    // Star data
    sf::Sprite  star_projectile;

    // Constructor and destructor
    Star();
    ~Star();
    
    // Star functions
    void    initializeStars(sf::Vector2f playerPosition);
    void    updateStars(float deltatime, std::vector<Star>&   stars);

private:
};