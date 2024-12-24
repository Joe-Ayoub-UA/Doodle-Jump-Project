//
// Created by s0230501 on 14/11/24.
//

#include "Player.h"

namespace Logic_Library {

    void Player::moveLeft() {
        float newX = observer->getMPlayer()->getPosition().x - horizontalSpeed * Config::frameDuration;
        float newY = observer->getMPlayer()->getPosition().y;
        Coordinates newCoordinates(newX, newY);
        observer->notifyPosition(newCoordinates);
    }

    void Player::moveRight() {
        float newX = observer->getMPlayer()->getPosition().x + horizontalSpeed * Config::frameDuration;
        float newY = observer->getMPlayer()->getPosition().y;
        Coordinates newCoordinates(newX, newY);
        observer->notifyPosition(newCoordinates);
    }

    void Player::assignObserver(std::shared_ptr<Game_Repr::Player> newObserver) {
        this->observer = std::move(newObserver);
    }

    void Player::deleteObserver() {
        observer = nullptr;
    }

    void Player::notifyObserver() {
        observer->update();
    }

    void Player::notifyPosition(const Coordinates& coordinates) {
        observer->notifyPosition(coordinates);
    }

    std::shared_ptr<Game_Repr::Player> Player::getObserver() {
        return this->observer;
    }
}