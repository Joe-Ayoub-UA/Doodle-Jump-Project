//
// Created by Joe Ayoub on 16/11/24 at 20:04.
//

#include "Controller.h"

void Controller::handlePlayerInputs(sf::Keyboard::Key key, bool isPressed) {
    if (key == sf::Keyboard::D or key == sf::Keyboard::Right) {
        right = isPressed;
    }

    if (key == sf::Keyboard::A or key == sf::Keyboard::Left) {
        left = isPressed;
    }

    if (key == sf::Keyboard::Space or key == sf::Keyboard::Up) {
        //std::cout << "Space pressed" << std::endl;
        jump = isPressed;
    }
}

Controller::Controller() {std::make_shared<Controller>(*this);}

Controller::~Controller() {

}
