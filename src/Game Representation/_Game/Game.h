//
// Created by Joe Ayoub on 14/11/24 at 15:49.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_GAME_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_GAME_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../../Controller/Controller.h"
#include <memory>
#include "../../Utilities/Stopwatch/Stopwatch.h"
#include "../Player/Player.h"
#include "../../Config.h"
//using namespace Logic_Library;
/**
 * @brief The Game class is the main class of the game. It is responsible of setting up the game, running the game and updating the game.
 */
class Game {
private:
    std::shared_ptr<Controller> mController{new Controller()};

    std::unique_ptr<sf::RenderWindow> mWindow{};

    std::shared_ptr<Game_Repr::Player> mPlayer{new Game_Repr::Player()};
//    sf::CircleShape mPlayer;

    std::shared_ptr<Stopwatch> mStopwatch{};

    sf::Event mEvent{};

    void processEvents();

    void applyGravity();

    void update(sf::Time delta);

    void render();
public:
    Game();

    void initgame();

    void run();
};


#endif //INC_2024_PROJECT_JOE_AYOUB_UA_GAME_H
