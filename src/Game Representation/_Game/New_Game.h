//
// Created by Joe Ayoub on 23/12/24 at 17:02.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_NEW_GAME_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_NEW_GAME_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>

#include "../../Logic Library/_World/World.h" // World
#include "../../Controller/Controller.h" // Controller
#include "../../Utilities/Stopwatch/Stopwatch.h" // Stopwatch, singleton
#include "../../Game Representation/Player/Player.h" // Class to view the player
#include "../../Game Representation/Platform/Platform.h" // Class to view the platform
#include "../../Game Representation/BG Tile/BG_Tile.h" // Class to view the background tile

#include "../../Config.h"


class New_Game {
private:
    /// @brief Controller of the game
    std::shared_ptr<Controller> mController{new Controller()};

    /// @brief Window of the game
    std::unique_ptr<sf::RenderWindow> mWindow{};

    /// @brief Player of the game
    std::shared_ptr<Game_Repr::Player> mPlayer{new Game_Repr::Player()};

    /// @brief Stopwatch of the game
    std::shared_ptr<Stopwatch> mStopwatch{};

    /// @brief Platforms of the game
    std::vector<std::shared_ptr<Logic_Library::Platform>> mPlatforms{};

    void gameInit();

    void processEvents();

    void applyGravity();

    void update(sf::Time delta);

    void render();

public:
    New_Game();

    void run();
};


#endif //INC_2024_PROJECT_JOE_AYOUB_UA_NEW_GAME_H
