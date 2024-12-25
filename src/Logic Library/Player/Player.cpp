//
// Created by s0230501 on 14/11/24.
//

#include "Player.h"

namespace Logic_Library {

    void Player::moveLeft() {
        float newX = observer->getMPlayer()->getPosition().x - horizontalSpeed * Config::frameDuration;
        float newY = observer->getMPlayer()->getPosition().y;
        Coordinates newCoordinates(newX, newY);
//        std::cout << "New coordinates: " << newCoordinates.getX() << " " << newCoordinates.getY() << std::endl;
        observer->notifyPosition(newCoordinates);
    }

    void Player::moveRight() {
        float newX = observer->getMPlayer()->getPosition().x + horizontalSpeed * Config::frameDuration;
        float newY = observer->getMPlayer()->getPosition().y;
        Coordinates newCoordinates(newX, newY);
//        std::cout << "New coordinates: " << newCoordinates.getX() << " " << newCoordinates.getY() << std::endl;
        observer->notifyPosition(newCoordinates);
    }

    Coordinates Player::teleportPlayer() {
        Coordinates coordinates = Coordinates(observer->getMPlayer()->getPosition().x, observer->getMPlayer()->getPosition().y);
        float x = coordinates.getX();
        float y = coordinates.getY();
        if (checkOutOfBounds(coordinates)) {
//            std::cout << "Out of bounds" << std::endl;
//            if (mPlayer->getMPlayer()->getPosition().x < mPlayer->getMPlayer()->getRadius()*(-2)) {
//                mPlayer->getMPlayer()->setPosition((float)mWindow->getSize().x+mPlayer->getMPlayer()->getRadius(),mPlayer->getMPlayer()->getPosition().y);
//            }
//            if (mPlayer->getMPlayer()->getPosition().x > (float)mWindow->getSize().x+mPlayer->getMPlayer()->getRadius()) {
//                mPlayer->getMPlayer()->setPosition(mPlayer->getMPlayer()->getRadius()*(-2),mPlayer->getMPlayer()->getPosition().y);
//            }
            float radius = this->getObserver()->getMPlayer()->getRadius();
            if (x <  radius * (-2)) {
                x = Config::windowWidth;
            }
            if (x > Config::windowWidth + radius) {
                x = radius * (-2);
            }
        }
        return {x,y};
    }

    bool Player::checkOutOfBounds(const Coordinates& coordinates) {
        return coordinates.getX() < 0 or coordinates.getX() > Config::windowWidth;
    }

    void Player::jump() {
//        verticalSpeed = -gravity * Config::frameDuration;
        verticalSpeed = -Config::jumpForce;
        float newX = observer->getMPlayer()->getPosition().x;
        float newY = observer->getMPlayer()->getPosition().y + verticalSpeed * Config::frameDuration;
        Coordinates newCoordinates(newX, newY);
        observer->notifyPosition(newCoordinates);
    }

    void Player::applyGravity() {
        verticalSpeed += gravity * Config::frameDuration;
        float newX = observer->getMPlayer()->getPosition().x;
        float newY = observer->getMPlayer()->getPosition().y + verticalSpeed * Config::frameDuration;
        Coordinates newCoordinates(newX, newY);
//        std::cout << "Vertical speed: " << verticalSpeed << std::endl;

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