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

    void Platform::moveUp() {
        float newX = observer->getMPlatform()->getPosition().x;
        float newY = observer->getMPlatform()->getPosition().y - verticalSpeed * Config::frameDuration;
        Coordinates newCoordinates(newX, newY);
        observer->notifyPosition(newCoordinates);
    }

    void Platform::moveDown() {
        float newX = observer->getMPlatform()->getPosition().x;
        float newY = observer->getMPlatform()->getPosition().y + verticalSpeed * Config::frameDuration;
        Coordinates newCoordinates(newX, newY);
        observer->notifyPosition(newCoordinates);
    }

    void Platform::moveLeft() {
        float newX = observer->getMPlatform()->getPosition().x - horizontalSpeed * Config::frameDuration;
        float newY = observer->getMPlatform()->getPosition().y;
        Coordinates newCoordinates(newX, newY);
        observer->notifyPosition(newCoordinates);
    }

    void Platform::moveRight() {
        float newX = observer->getMPlatform()->getPosition().x + horizontalSpeed * Config::frameDuration;
        float newY = observer->getMPlatform()->getPosition().y;
        Coordinates newCoordinates(newX, newY);
        observer->notifyPosition(newCoordinates);
    }

    void Platform::fixTooHigh(float moveDownDistance) {
        float newX = observer->getMPlatform()->getPosition().x;
        float newY = observer->getMPlatform()->getPosition().y + moveDownDistance;
        Coordinates newCoordinates(newX, newY);
        this->setPosition(newCoordinates);
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
}
