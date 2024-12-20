//
// Created by s0230501 on 14/11/24.
//

#include "Player.h"

namespace Logic_Library {

    void Player::assignObserver(std::shared_ptr<Observer> newObserver) {
        this->observer = std::move(newObserver);
    }

    void Player::deleteObserver() {
        observer = nullptr;
    }

    void Player::notifyObserver() {
        observer->update();
    }
}