//
//  Game.h
//  Black Cat Sanctuary
//
//  Created by Sarita Sulkumäki on 11.11.2024.
//

#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Keyboard.hpp>

#include <memory>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

#include "Audio.h"
#include "Constants.h"
#include "InputHandler.h"
#include "Obstacle.h"
#include "Player.h"
#include "ResourceManager.h"
#include "Star.h"

enum gameState
{
    GAMESTATE_MENU,
    GAMESTATE_PLAY,
    GAMESTATE_PUZZLE,
    GAMESTATE_PAUSE,
    GAMESTATE_GAMEOVER
};

class Game
{
public:
    // Game window
    sf::RenderWindow        window;

    // Deltatime
    sf::Time                deltatime;
    sf::Clock               clock;

    // Game
    int                     game_state;
    int                     spawn_count;
    int                     score;

    // Classes
    Player                  player;
    Audio                   audio;
    Input                   input;
    Obstacle                obstacle;

    // Vectors
    std::vector<Star>       stars;
    std::vector<Obstacle>   obstacles;
    
    // Textures
    sf::Texture             background_tex;
    sf::Texture             title_tex;
    sf::Texture             player_tex;
    sf::Texture             wall_tex;
    sf::Texture             cat_tex;
    sf::Texture             enemy_tex;
    sf::Texture             door_tex;
    sf::Texture             star_tex;
    sf::Texture             hit_tex;
    sf::Texture             rune_1_tex;
    sf::Texture             rune_2_tex;
    sf::Texture             rune_3_tex;
    sf::Texture             rune_4_tex;
    sf::Texture             rune_5_tex;
    sf::Texture             paw_tex;

    // Font
    sf::Font                font;
    

    // Constructor and destructor
    Game();
    ~Game();

    // Initialize
    bool    initialize();
    void    setTextures();

    // Game loop functions
    void    handleEvents(sf::Event &event);
    // void    handleInput();
    void    render();

private:
    // Background
    sf::Sprite      background;
    sf::Sprite      background_extension;
    sf::Sprite      paw;
    sf::Sprite      title;
    sf::Sprite      start_button;
    sf::Sprite      quit_button;

    // Texts
    sf::Text        score_display;
    sf::Text        game_over;
    sf::Text        start;
    sf::Text        quit;
    sf::FloatRect   text_rect;

    void    updateScrollingBackground();

    // Event handling functions
    // void    handleMouseClickEvents();
    // void    handleMouseHoverEvents();
    // void    handleMousePressEvents();

    // Rendering functions
    void    renderMenu();
    void    renderGameplayFlying();
    void    renderGameplayPuzzle();
    void    renderPause();
    void    renderGameover();

};

// class Player;
// class Game;
// class GameInput;
// class Vampire;

// namespace sf { class Clock; }

// class Game : public sf::Drawable
// {
// public:
    
//     enum class State
//     {
//         WAITING,
//         ACTIVE,
//     };
    
//     Game();
//     ~Game();
    
//     bool initialise();
//     void update(float deltaTime);
//     void resetLevel();
//     void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    
//     State getState() const { return m_state; }
    
//     void onKeyPressed(sf::Keyboard::Key key);
//     void onKeyReleased(sf::Keyboard::Key key);

//     Player* getPlayer() const;
//     sf::Texture* getPlayerTexture() { return &m_playerTexture; }
//     sf::Texture* getVampireTexture() { return &m_vampTexture; }

//     void vampireSpawner(float deltaTime);

// private:
//     std::unique_ptr<Player> m_pPlayer;

//     std::vector<std::unique_ptr<Vampire>> m_pVampires;

//     State m_state;
//     std::unique_ptr<sf::Clock> m_pClock;
//     std::unique_ptr<GameInput> m_pGameInput;

//     float m_vampireCooldown = 0.0f;
//     float m_nextVampireCooldown = 2.0f;
//     int m_spawnCount = 0;
    
//     sf::Font m_font;
//     sf::Texture m_vampTexture;
//     sf::Texture m_playerTexture;
// };
