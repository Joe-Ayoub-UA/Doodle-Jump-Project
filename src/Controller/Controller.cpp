//
// Created by Joe Ayoub on 16/11/24 at 20:04.
//

#include "Controller.h"

void Controller::handleInputs(sf::Keyboard::Key key, bool isPressed) {
    if (key == sf::Keyboard::D or key == sf::Keyboard::Right) {
        right = isPressed;
    }

    if (key == sf::Keyboard::A or key == sf::Keyboard::Left) {
        left = isPressed;
    }
}
