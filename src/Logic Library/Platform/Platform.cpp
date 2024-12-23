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

    float Platform::getX() const {
        return x;
    }

    void Platform::setX(float n_x) {
        Platform::x = n_x;
    }

    float Platform::getY() const {
        return y;
    }

    void Platform::setY(float n_y) {
        Platform::y = n_y;
    }

    void Platform::setPosition(float n_x, float n_y) {
        this->setX(n_x);
        this->setY(n_y);
    }

    void Platform::moveUp() {
        this->setPosition(this->getX(), this->getY() - 1.f);
    }

    void Platform::moveDown() {
        this->setPosition(this->getX(), this->getY() + 1.f);
    }

    void Platform::moveLeft() {
        this->setPosition(this->getX() - 1.f, this->getY());
    }

    void Platform::moveRight() {
        this->setPosition(this->getX() + 1.f, this->getY());
    }

    void Platform::assignObserver(std::shared_ptr<Observer> newObserver) {
        this->observer = std::move(newObserver);
    }

    void Platform::deleteObserver() {
        this->observer = nullptr;
    }

    void Platform::notifyObserver() {
        observer->update();
    }
}
