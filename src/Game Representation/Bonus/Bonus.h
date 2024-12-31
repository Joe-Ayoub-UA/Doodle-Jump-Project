//
// Created by Joe Ayoub on 16/11/24 at 19:19.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_BONUS_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_BONUS_H
#include <iostream>
#include <memory>
#include "../SFML/Graphics.hpp"

namespace Game_Repr {

    class Bonus {
    private:
        std::shared_ptr<sf::CircleShape> mBonus;
    };

} // Logic_Library

#endif //INC_2024_PROJECT_JOE_AYOUB_UA_BONUS_H
