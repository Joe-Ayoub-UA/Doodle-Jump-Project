//
// Created by Joe Ayoub on 19/12/24 at 22:30.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_CONFIG_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_CONFIG_H
/**
 * @brief Config class: has all the parameters that are used in the game, in one file so they are easier to change
 */
class Config {
public:
    /**
     * @brief Width of the window
     */
    static constexpr int windowWidth = 600; // Width of the window
    /**
     * @brief Height of the window
     */
    static constexpr int windowHeight = 800; // Height of the window
    /**
     * @brief Horizontal speed of the player
     */
    static constexpr float horizontalSpeed = 500.f;
    /**
     * @brief Gravity of the game
     */
//    static constexpr float gravity = 9.8f;
    static constexpr float gravity = 90.8f;
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
    /**
     * @brief Platform's horizontal speed
     */
    static constexpr float platformHorizontalSpeed = 100.f;
    /**
     * @brief Platform's vertical speed
     */
    static constexpr float platformVerticalSpeed = 100.f;
};

#endif //INC_2024_PROJECT_JOE_AYOUB_UA_CONFIG_H
