//
// Created by Joe Ayoub on 23/12/24 at 17:02.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_NEW_GAME_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_NEW_GAME_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>
#include <thread>

#include "../../Logic Library/_World/World.h" // World
#include "../../Controller/Controller.h" // Controller
#include "../../Utilities/Stopwatch/Stopwatch.h" // Stopwatch, singleton
#include "../../Game Representation/Player/Player.h" // Class to view the player
#include "../../Game Representation/Platform/Platform.h" // Class to view the platform
#include "../../Game Representation/BG Tile/BG_Tile.h" // Class to view the background tile

#include "../../Config.h"

/**
 * @brief Class to represent the game
 */
class New_Game {
private:
    /// @brief Controller of the game
    std::shared_ptr<Controller> mController{};

    /// @brief Factory of the game
    std::shared_ptr<Concrete_Factory> CF{new Concrete_Factory()};

    /// @brief Window of the game
    std::unique_ptr<sf::RenderWindow> mWindow{};

    /// @brief Player of the game
    std::shared_ptr<Game_Repr::Player> mPlayer{};

    /// @brief Platforms of the game
    std::vector<std::shared_ptr<Game_Repr::Platform>> mPlatforms{};

    /// @brief unordered_map of the states of the keys
    std::unordered_map<sf::Keyboard::Key, bool> mKeyStates{};

    /// @brief Text for the score
    sf::Text mText{};

    /// @brief Font for the text
    sf::Font mFont{};

    /// @brief Text for the highscore
    sf::Text mHighScoreText{};

    /// @brief Font for the highscore
    sf::Font mHighScoreFont{};

    /// @brief Last score
    int lastScore = 0;

    /**
     * @brief This functions handles the player inputs to move the player
     * @param key
     */
    void handlePlayerInputs(sf::Keyboard::Key key, bool isPressed);

    /**
     * @brief This function initializes the game
     */
    void gameInit();

    /**
     * @brief This function processes the events of the game
     */
    void processEvents();

    /**
     * @brief This function updates the game
     * @param delta
     */
    void update();

    /**
     * @brief This function renders the game
     */
    void render();

    /**
     * @brief This function sleeps for a certain amount of time
     * @param time
     */
    void sleep(float time);

public:
    /**
     * @brief Default constructor for the New_Game class
     */
    New_Game();

    /**
     * @brief This function runs the game
     */
    void run();
};


#endif //INC_2024_PROJECT_JOE_AYOUB_UA_NEW_GAME_H
