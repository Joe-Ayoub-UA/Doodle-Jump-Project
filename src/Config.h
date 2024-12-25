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
    static constexpr float gravity = 250.f;
//    static constexpr float gravity = 0.028f;

    /**
     * @brief Jump force of the player
     */
    static constexpr float jumpForce = 350.f;
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
    static constexpr float platformWidth = 150.f;

    /**
     * @brief Platform's height
     */
    static constexpr float platformHeight = 20.f;

    /**
     * @brief Platform's horizontal speed
     */
    static constexpr float platformHorizontalSpeed = 100.f;

    /**
     * @brief Platform's vertical speed
     */
    static constexpr float platformVerticalSpeed = 100.f;

    /**
     * @brief Amount of platforms
     */
    static constexpr int amountOfPlatforms = 15;
    /**
     * @brief Gets the minimum distance range between platforms based on the amount of platforms
     * @return A pair representing the minimum distance range
     */
    static std::pair<float, float> getMinPlatformDistance() {
        float minDistance = 50.f + (15 - amountOfPlatforms) * 10.f;
        float maxDistance = 100.f + (15 - amountOfPlatforms) * 20.f;
        return std::make_pair(minDistance, maxDistance);
    }
//    static constexpr int amountOfPlatforms = 15;

    /**
     * @brief Minimum distance range between platforms
     */
    static const std::pair<float,float> minPlatformDistance;


    static const std::map<Enums::PlatformType, std::string> platformColor;
};

#endif //INC_2024_PROJECT_JOE_AYOUB_UA_CONFIG_H
