//
//  Main.cpp
//  Black Cat Sanctuary
//
//  Created by Sarita Sulkumäki on 11.11.2024.
//

#include "Game.h"

// Start of the game. Initial game loop.
int main(int argc, char* argv[])
{
    // ResourceManager Must be Instantiated here -- DO NOT CHANGE
    ResourceManager::init(argv[0]);

    Game    game;

    if (!game.initialize())
    {
        std::cerr << "Error // Game failed to initialise. Window closed." << std::endl;
        return (EXIT_FAILURE);
    }

    // Check that background music starts playing.
   if (!game.audio.playMusic())
       std::cerr << "Error // Failed to play background music." << std::endl;
    // Run the program as long as the window is open.
    while (game.window.isOpen())
    {
         // Get deltatime
        game.deltatime = game.clock.restart();
        sf::Event event;
        // Check for new events in the window and handle them.
        while (game.window.pollEvent(event))
            game.handleEvents(event);
        // game.handleInput();
        // Render the content to the window.
        game.render();
    }
    return (EXIT_SUCCESS);
}

// int main(int argc, char* argv[])
// {
//     // ResourceManager Must be Instantiated here -- DO NOT CHANGE
//     ResourceManager::init(argv[0]);

//     sf::RenderWindow window(sf::VideoMode(ScreenWidth, ScreenHeight), "Survive");
//     window.setKeyRepeatEnabled(false);
    
//     std::unique_ptr<Game> pGame = std::make_unique<Game>();
//     if (!pGame->initialise())
//     {
//         std::cerr << "Game Failed to initialise" << std::endl;
//         return 1;
//     }
    
//     sf::Clock clock;
//     // run the program as long as the window is open
//     while (window.isOpen())
//     {
//         // check all the window's events that were triggered since the last iteration of the loop
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             switch(event.type)
//             {
//                 case sf::Event::Closed:
//                     // "close requested" event: we close the window
//                     window.close();
//                     break;
//                 case sf::Event::KeyPressed:
//                     pGame->onKeyPressed(event.key.code);
//                     break;
//                 case sf::Event::KeyReleased:
//                     pGame->onKeyReleased(event.key.code);
//                     break;
//                 default:
//                     break;
//             }
//         }
        
//         sf::Time elapsedTime = clock.getElapsedTime();
//         clock.restart();
//         pGame->update(elapsedTime.asSeconds());
        
//         // clear the window with black color
//         window.clear(sf::Color::Black);
        
//         window.draw(*pGame.get());
        
//         // end the current frame
//         window.display();
//     }
    
//     return 0;
// }
