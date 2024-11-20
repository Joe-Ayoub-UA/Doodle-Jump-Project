//
// Created by Joe Ayoub on 16/11/24 at 20:04.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_CONTROLLER_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_CONTROLLER_H
#include "SFML/Graphics.hpp"
#include <iostream>

class Controller {
public:

    void handleInputs(sf::Keyboard::Key key, bool isPressed);

    bool left{};
    bool right{};
};


#endif //INC_2024_PROJECT_JOE_AYOUB_UA_CONTROLLER_H
