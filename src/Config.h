//
// Created by Joe Ayoub on 19/12/24 at 22:30.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_CONFIG_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_CONFIG_H

class Config {
public:
    static constexpr float horizontalSpeed = 350.f;
//    static constexpr float gravity = 9.8f;
    static constexpr float gravity = 90.8f;
    static constexpr float frameDuration = 1.f / 60.f;
    static constexpr float radiusMultiplier = -2.f; // Multiplier for player's radius
    static constexpr float sizeOffset = 1.f; // Offset for window size
};

#endif //INC_2024_PROJECT_JOE_AYOUB_UA_CONFIG_H
