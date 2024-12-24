//
// Created by Joe Ayoub on 16/11/24 at 20:04.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_CONTROLLER_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_CONTROLLER_H
#include "SFML/Graphics.hpp"
#include <iostream>
#include <memory>


/**
 * @brief Class that is responsible of handling changes
 */
class Controller {
public:
    Controller();

    void handlePlayerInputs(sf::Keyboard::Key key, bool isPressed);

    bool left{};
    bool right{};
    bool jump{};

    virtual ~Controller();
};


#endif //INC_2024_PROJECT_JOE_AYOUB_UA_CONTROLLER_H
