//
// Created by s0230501 on 14/11/24.
//

#include "Platform.h"

#include <utility>
namespace Logic_Library {

    void Platform::createPlatform() {
        int random = Random::getInstance().randomInt(1,10);
        if (random <= 7) {
            // 70% probability of a creating static platform
            this->setPType(Enums::PlatformType::STATIC);
        }
        else if (random == 8) {
            // 10% probability of a creating horizontal platform
            this->setPType(Enums::PlatformType::HORIZONTAL);
        }
        else if (random == 9) {
            // 10% probability of a creating vertical platform
            this->setPType(Enums::PlatformType::VERTICAL);
        }
        else if (random == 10) {
            // 10% probability of a creating temporary platform
            this->setPType(Enums::PlatformType::TEMPORARY);
        }

    }

//    void Platform::setPosition(Coordinates &coordinates) {
//        this->pCoordinates = coordinates;
//    }
///@todo Make sure the vertical platforms go over a fixed distance and not over the whole window, idea is that when i
///  move the platforms down then the fixed distance also goes down so the platform doesnt for example go up forever.
    void Platform::moveUp() {
        float newX = observer->getMPlatform()->getPosition().x;
        float newY = observer->getMPlatform()->getPosition().y - verticalSpeed * Config::frameDuration;
        Coordinates newCoordinates(newX, newY);
        if (newY <= 0) {
            this->setGoingUp(false);
        }
        observer->notifyPosition(newCoordinates);
    }

    void Platform::moveDown() {
        float newX = observer->getMPlatform()->getPosition().x;
        float newY = observer->getMPlatform()->getPosition().y + verticalSpeed * Config::frameDuration;
        Coordinates newCoordinates(newX, newY);
        if (newY+Config::platformHeight >= Config::windowHeight) {
            this->setGoingUp(true);
        }
        observer->notifyPosition(newCoordinates);
    }

    void Platform::moveLeft() {
        float newX = observer->getMPlatform()->getPosition().x - horizontalSpeed * Config::frameDuration;
        float newY = observer->getMPlatform()->getPosition().y;
        Coordinates newCoordinates(newX, newY);
        if (newX <= 0) {
            this->setGoingLeft(false);
        }
        observer->notifyPosition(newCoordinates);
    }

    void Platform::moveRight() {
        float newX = observer->getMPlatform()->getPosition().x + horizontalSpeed * Config::frameDuration;
        float newY = observer->getMPlatform()->getPosition().y;
        Coordinates newCoordinates(newX, newY);
        if (newX+Config::platformWidth >= Config::windowWidth) {
            this->setGoingLeft(true);
        }
        observer->notifyPosition(newCoordinates);
    }

    void Platform::fixTooHigh(float moveDownDistance) {
        float newX = observer->getMPlatform()->getPosition().x;
        float newY = observer->getMPlatform()->getPosition().y + moveDownDistance;
        Coordinates newCoordinates(newX, newY);
        this->getObserver()->setPosition(newCoordinates);
        observer->notifyPosition(newCoordinates);
    }

    void Platform::assignObserver(std::shared_ptr<Game_Repr::Platform> newObserver) {
        this->observer = std::move(newObserver);
    }

    void Platform::deleteObserver() {
        this->observer = nullptr;
    }

    void Platform::notifyObserver() {
        observer->update();
    }

    void Platform::notifyPosition(const Coordinates& coordinates) {
        observer->notifyPosition(coordinates);
    }

    bool Platform::isGoingLeft() const {
        return goingLeft;
    }

    void Platform::setGoingLeft(bool n_goingLeft) {
        Platform::goingLeft = n_goingLeft;
    }

    bool Platform::isGoingUp() const {
        return goingUp;
    }

    void Platform::setGoingUp(bool n_goingUp) {
        Platform::goingUp = n_goingUp;
    }
}
