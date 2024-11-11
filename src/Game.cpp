//
//  Game.cpp
//  Black Cat Sanctuary
//
//  Created by Sarita Sulkumäki on 11.11.2024.
//

#include "Game.h"

// Constructor
Game::Game()
{
    window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Black Cat Sanctuary", sf::Style::Titlebar | sf::Style::Close);
    game_state = GAMESTATE_PLAY;
    background.setPosition(0.0f, 0.0f);
    background_extension.setPosition(WINDOW_WIDTH, 0.0f);
    spawn_count = 0;
}

// Destructor
Game::~Game()
{

}

// Initialize game data
bool    Game::initialize()
{
    // Load font
    if (!font.loadFromFile(ResourceManager::getFilePath("Cattie.ttf")))
    {
        std::cerr << "Error // Unable to load font." << std::endl;
        return (false);
    }
    // Load textures
    if (!background_tex.loadFromFile(ResourceManager::getFilePath("background.png")) ||
        !title_tex.loadFromFile(ResourceManager::getFilePath("title.png")) ||
        !player_tex.loadFromFile(ResourceManager::getFilePath("witch.png")) ||
        !wall_tex.loadFromFile(ResourceManager::getFilePath("obstacle.png")) ||
        !cat_tex.loadFromFile(ResourceManager::getFilePath("cat.png")) ||
        !enemy_tex.loadFromFile(ResourceManager::getFilePath("ghost.png")) ||
        !door_tex.loadFromFile(ResourceManager::getFilePath("door.png")) ||
        !star_tex.loadFromFile(ResourceManager::getFilePath("star.png")) ||
        !hit_tex.loadFromFile(ResourceManager::getFilePath("spell_impact.png")) ||
        !rune_1_tex.loadFromFile(ResourceManager::getFilePath("rune_1.png")) ||
        !rune_2_tex.loadFromFile(ResourceManager::getFilePath("rune_2.png")) ||
        !rune_3_tex.loadFromFile(ResourceManager::getFilePath("rune_3.png")) ||
        !rune_4_tex.loadFromFile(ResourceManager::getFilePath("rune_4.png")) ||
        !rune_5_tex.loadFromFile(ResourceManager::getFilePath("rune_5.png")) ||
        !paw_tex.loadFromFile(ResourceManager::getFilePath("paw.png")))
    {
        std::cerr << "Error // Unable to load textures." << std::endl;
        return (false);
    }
    if (!audio.background_music.openFromFile(ResourceManager::getFilePath("background_music.ogg")))
    {
        std::cerr << "Error // Unable to open audio file." << std::endl;
        return (false);
    }
    return (true);
}

// Set textures to sprites
void    Game::setTextures()
{
    background.setTexture(background_tex);
    background_extension.setTexture(background_tex);
    player.body.setTexture(player_tex);
}

// Handles events
void    Game::handleEvents(sf::Event &event)
{
        switch (event.type)
    {
        case sf::Event::Closed:
            window.close();
            break;
        default:
            break;
        }
}

// Checks game state to decide what to render on screen
void    Game::render()
{
    // Clear window
    window.clear();
    // Renders correct things based on the game state
    switch (game_state)
    {
        case GAMESTATE_MENU:
            renderMenu();
            break;
        case GAMESTATE_PLAY:
            renderGameplayFlying();
            break;
        case GAMESTATE_PUZZLE:
            renderGameplayPuzzle();
            break;
        case GAMESTATE_PAUSE:
            renderPause();
            break;
        case GAMESTATE_GAMEOVER:
            renderGameover();
            break;
    }
    // Display everything on the window
    window.display();
}

// Renders the menu
void    Game::renderMenu()
{
    window.draw(background);
}

// Renders the part of gameplay where the player avoids obstacles
void    Game::renderGameplayFlying()
{
    updateScrollingBackground();
    // Draw background on window
    window.draw(background);
    window.draw(background_extension);
    // Draw player on window
    window.draw(player.body);
    // Draw star spells
    for (const auto& star : stars)
        window.draw(star.star_projectile);
}

// Renders the part of the gameplay that holds the puzzle
void    Game::renderGameplayPuzzle()
{
    
}

// Renders paused game
void    Game::renderPause()
{

}

// Renders game over
void    Game::renderGameover()
{

}

// Updates background position to create a scrolling effect on a loop
void    Game::updateScrollingBackground()
{
    // Move background with each frame
    background.move(-SCROLL_SPEED * deltatime.asSeconds(), 0.0f);
    background_extension.move(-SCROLL_SPEED * deltatime.asSeconds(), 0.0f);
    // Set background back to right side of screen when going off bounds to create scrolling effect
    if (background.getPosition().x <= -WINDOW_WIDTH)
        background.setPosition(static_cast<int>(background_extension.getPosition().x + WINDOW_WIDTH), 0.0f);
    if (background_extension.getPosition().x <= -WINDOW_WIDTH)
        background_extension.setPosition(static_cast<int>(background.getPosition().x + WINDOW_WIDTH), 0.0f);
}


// #include "Game.h"

// #include <SFML/Graphics.hpp>
// #include <SFML/System.hpp>
// #include <iostream>

// #include "ResourceManager.h"
// #include "InputHandler.h"
// #include "Weapon.h"
// #include "Player.h"
// #include "Rectangle.h"
// #include "Vampire.h"

// Game::Game() :
//     m_state(State::WAITING),
//     m_pClock(std::make_unique<sf::Clock>()),
//     m_pPlayer(std::make_unique<Player>(this)),
//     m_vampireCooldown(2.0f),
//     m_nextVampireCooldown(2.0f)
// {
//     m_pGameInput = std::make_unique<GameInput>(this, m_pPlayer.get());
// }

// Game::~Game()
// {
// }

// bool Game::initialise()
// {
//     /*
//         PAY ATTENTION HIVER!
//             If you want to load any assets (fonts, textures) please use the pattern shown below
//     */

//     if (!m_font.loadFromFile(ResourceManager::getFilePath("Lavigne.ttf")))
//     {
//         std::cerr << "Unable to load font" << std::endl;
//         return false;
//     }
//     if (!m_vampTexture.loadFromFile(ResourceManager::getFilePath("vampire.png")))
//     {
//         std::cerr << "Unable to load texture" << std::endl;
//         return false;
//     }
//     if (!m_playerTexture.loadFromFile(ResourceManager::getFilePath("player.png")))
//     {
//         std::cerr << "Unable to load texture" << std::endl;
//         return false;
//     }

//     resetLevel();
//     return true;
// }

// void Game::resetLevel()
// {
//     m_pVampires.clear();

//     m_pPlayer->initialise();
//     m_pClock->restart();
// }

// void Game::update(float deltaTime)
// {
//     switch (m_state)
//     {
//         case State::WAITING:
//         {
//             if (m_pClock->getElapsedTime().asSeconds() >= 3.f)
//             {
//                 m_state = State::ACTIVE;
//                 m_pClock->restart();
//             }
//         }
//         break;
            
//         case State::ACTIVE:
//         {
//             m_pGameInput->update(deltaTime);
//             m_pPlayer->update(deltaTime);

//             vampireSpawner(deltaTime);
//             for (auto& temp : m_pVampires)
//             {
//                 temp->update(deltaTime);
//             }

//             if (m_pPlayer->isDead())
//             {
//                 m_state = State::WAITING;
//                 resetLevel();
//             }
//         }
//         break;
//     }

//     int i = 0;
//     while (i < m_pVampires.size())
//     {
//         if (m_pVampires[i]->isKilled())
//         {
//             std::swap(m_pVampires[i], m_pVampires.back());
//             m_pVampires.pop_back();
//             continue;
//         }
//         i++;
//     }
// }

// void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const
// {
//     //  Draw texts.
//     if (m_state == State::WAITING)
//     {
//         sf::Text startText;
//         startText.setFont(m_font);
//         startText.setString("Game Start!");
//         startText.setFillColor(sf::Color::White);
//         startText.setPosition(80.0f, 80.0f);
//         startText.setStyle(sf::Text::Bold);
//         target.draw(startText);
//     }
//     else
//     {
//         sf::Text timerText;
//         timerText.setFont(m_font);
//         timerText.setFillColor(sf::Color::White);
//         timerText.setStyle(sf::Text::Bold);
//         timerText.setString(std::to_string((int)m_pClock->getElapsedTime().asSeconds()));
//         timerText.setPosition(sf::Vector2f((ScreenWidth - timerText.getLocalBounds().getSize().x) * 0.5, 20));
//         target.draw(timerText);
//     }

//     // Draw player.
//     m_pPlayer->draw(target, states);

//     //  Draw world.
//     for (auto& temp : m_pVampires)
//     {
//         temp->draw(target, states);
//     }
// }


// void Game::onKeyPressed(sf::Keyboard::Key key)
// {
//     m_pGameInput->onKeyPressed(key);
// }

// void Game::onKeyReleased(sf::Keyboard::Key key)
// {
//     m_pGameInput->onKeyReleased(key);
// }

// Player* Game::getPlayer() const 
// {
//     return m_pPlayer.get();
// }

// void Game::vampireSpawner(float deltaTime)
// {
//     if (m_vampireCooldown > 0.0f)
//     {
//         m_vampireCooldown -= deltaTime;
//         return;
//     }

//     float randomXPos = rand() % ScreenWidth;
//     float randomYPos = rand() % ScreenHeight;

//     float distToRight = (float) ScreenWidth - randomXPos;
//     float distToBottom = (float) ScreenHeight - randomYPos;

//     float xMinDist = randomXPos < distToRight ? -randomXPos : distToRight;
//     float yMinDist = randomYPos < distToBottom ? -randomYPos : distToBottom;

//     if (abs(xMinDist) < abs(yMinDist))
//         randomXPos += xMinDist;
//     else
//         randomYPos += yMinDist;

//     sf::Vector2f spawnPosition = sf::Vector2f(randomXPos, randomYPos);
//     m_pVampires.push_back(std::make_unique<Vampire>(this, spawnPosition));

//     m_spawnCount++;
//     if (m_spawnCount % 5 == 0)
//     {
//         m_nextVampireCooldown -= 0.1f;
//     }
//     m_vampireCooldown = m_nextVampireCooldown;
// }