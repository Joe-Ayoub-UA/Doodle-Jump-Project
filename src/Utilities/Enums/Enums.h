//
// Created by Joe Ayoub on 23/12/24 at 17:46.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_ENUMS_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_ENUMS_H

/**
 * @brief Class that contains all the enums used in the game
 */
class Enums {
public:
    /**
     * @brief Enum that contains the different types of platforms
     */
    enum PlatformType {
        STATIC,
        HORIZONTAL,
        VERTICAL,
        TEMPORARY
    };

    /**
     * @brief Enum that contains the different types of bonuses
     */
    enum BonusType {
        NONE,
        JETPACK,
        SPRING,
    };
};
#endif //INC_2024_PROJECT_JOE_AYOUB_UA_ENUMS_H
