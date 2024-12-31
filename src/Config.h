//
// Created by Joe Ayoub on 19/12/24 at 22:30.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_CONFIG_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_CONFIG_H
#include <map>
#include "Utilities/Enums/Enums.h"
#include <iostream>
/**
 * @brief Config class: has all the parameters that are used in the game, in one file so they are easier to change
 */

class Config {
public:
    // Window
    // ====================================================Window=======================================================
    /**
     * @brief Width of the window
     */
    static constexpr int windowWidth = 600; // Width of the window

    /**
     * @brief Height of the window
     */
    static constexpr int windowHeight = 800; // Height of the window

    // =================================================================================================================

    // Player
    // ==================================================Player=========================================================

    /**
     * @brief Horizontal speed of the player
     */
    static constexpr float horizontalSpeed = 500.f;

    /**
     * @brief Gravity of the game
     */
//    static constexpr float gravity = 9.81;
//    static constexpr float gravity = 90.8f;
//    static constexpr float gravity = 350.f;
    static constexpr float gravity = 550.f;
//    static constexpr float gravity = 0.028f;

    /**
     * @brief Jump force of the player
     */
//    static constexpr float jumpForce = 350.f;
//    static constexpr float jumpForce = 350.f;
    static constexpr float jumpForce = 450.f;
//    static constexpr float jumpForce = 30.f;
    // =================================================================================================================

    // Frame
    /**
     * @brief Duration of a frame
     */
    static constexpr float frameDuration = 1.f / 60.f;

    /**
     * @brief Multiplier for player's radius
     */
    static constexpr float radiusMultiplier = -2.f; // Multiplier for player's radius

    /**
     * @brief Offset for window size
     */
    static constexpr float sizeOffset = 1.f; // Offset for window size


    // Platform
    // ==================================================PLATFORM=======================================================
    /**
     * @brief Platform's width
     */
//    static constexpr float platformWidth = 150.f;
    static constexpr float platformWidth = 100.f;

    /**
     * @brief Platform's height
     */
    static constexpr float platformHeight = 20.f;

    /**
     * @brief Platform's horizontal speed
     */
    static constexpr float platformHorizontalSpeed = 50.f;

    /**
     * @brief Platform's vertical speed
     */
    static constexpr float platformVerticalSpeed = 50.f;

    /**
     * @brief Amount of platforms
     */
    static int amountOfPlatforms;
    /**
     * @brief Gets the minimum distance range between platforms based on the amount of platforms
     * @return A pair representing the minimum distance range
     */
    static std::pair<float, float> getMinPlatformDistance() {
        float xDistance = 75.f + (15 - amountOfPlatforms) * 1.5;
        float yDistance = 125.f + (15 - amountOfPlatforms) * 2.5;
        return std::make_pair(xDistance, yDistance);
    }


    /**
     * @brief Gets the maximum distance range between platforms based on the amount of platforms
     * @return A pair representing the maximum distance range
     */
    static std::pair<float, float> getMaxPlatformDistance() {
        float xDistance = 100.f + (15 - amountOfPlatforms) * 2;
        float yDistance = 150.f + (15 - amountOfPlatforms) * 3;
        return std::make_pair(xDistance, yDistance);
    }
//    static constexpr int amountOfPlatforms = 15;

    /**
     * @brief Minimum distance range between platforms
     */
    static const std::pair<float,float> minPlatformDistance;

    static const std::pair<float,float> maxPlatformDistance;


    static const std::map<Enums::PlatformType, std::string> platformColor;

    static constexpr float platformPositionOffset = 100.f;
};

#endif //INC_2024_PROJECT_JOE_AYOUB_UA_CONFIG_H
