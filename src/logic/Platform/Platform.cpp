//
// Created by s0230501 on 14/11/24.
//

#include "Platform.h"

#include <utility>
namespace Logic_Library {

    void Platform::createPlatform() {
        int random = Random::getInstance().randomInt(1,20);
        if (random <= 17) {
            // 70% probability of a creating static platform
            this->setPType(Enums::PlatformType::STATIC);
        }
        else if (random == 18) {
            // 10% probability of a creating horizontal platform
            this->setPType(Enums::PlatformType::HORIZONTAL);
        }
        else if (random == 19) {
            // 10% probability of a creating vertical platform
            this->setPType(Enums::PlatformType::VERTICAL);
        }
        else if (random == 20) {
            // 10% probability of a creating temporary platform
            this->setPType(Enums::PlatformType::TEMPORARY);
        }


        // Code for adding a bonus to a platform
        int random2 = Random::getInstance().randomInt(1,20);
        if (random2 == 4) {
            // 10% probability of a creating jetpack bonus
            setHasBonus(true);
            setBonus(std::make_shared<Logic_Library::Bonus>(Enums::BonusType::JETPACK));
        }
        else if (random2 == 6) {
            // 10% probability of a creating spring bonus
            setHasBonus(true);
            setBonus(std::make_shared<Logic_Library::Bonus>(Enums::BonusType::SPRING));
        }
        else {
            // 80% probability of no bonus
            setHasBonus(false);
            setBonus(nullptr);
        }

    }

    void Platform::moveUp() {
        Coordinates current = observer->getPosition();
        current.setY(current.getY() - verticalSpeed * Config::frameDuration);

        // Check if reached upper boundary
        if (current.getY() <= mVerticalMin) {
            current.setY(mVerticalMin);
            goingUp = false; // change direction
        }

        observer->notifyPosition(current);
    }

    void Platform::moveDown() {
        Coordinates current = observer->getPosition();
        current.setY(current.getY() + verticalSpeed * Config::frameDuration);

        // Check if reached lower boundary
        if (current.getY() >= mVerticalMax) {
            current.setY(mVerticalMax);
            goingUp = true; // change direction
        }

        observer->notifyPosition(current);
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

        // Update vertical movement range when platform moves down
        if (this->getPType() == Enums::VERTICAL) {
            mVerticalMin += moveDownDistance;
            mVerticalMax += moveDownDistance;
        }
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

    bool Platform::getHasBonus() const {
        return hasBonus;
    }

    void Platform::setHasBonus(bool n_hasBonus) {
        Platform::hasBonus = n_hasBonus;
    }
}
