//
// Created by Joe Ayoub on 16/11/24 at 19:17.
//

#include "Platform.h"

namespace Game_Repr {
    Platform::Platform() : mPlatform(std::make_shared<sf::RectangleShape>(sf::Vector2f(Config::platformWidth, Config::platformHeight))) {
        mPlatform->setOutlineThickness(2.f);
            mPlatform->setOutlineColor(sf::Color::Black);
    }

    const std::shared_ptr<sf::RectangleShape> &Platform::getMPlatform() const {
        return mPlatform;
    }

    void Platform::setMPlatform(const std::shared_ptr<sf::RectangleShape> &n_mPlatform) {
        Platform::mPlatform = n_mPlatform;
    }

    const Coordinates &Platform::getPosition() const {
        return position;
    }

    void Platform::setPosition(const Coordinates &n_position) {
        Platform::position = n_position;
    }

    void Platform::setPlatformPos(float x, float y) {
        this->setPosition(Coordinates(x,y));
        mPlatform->setPosition(x, y);
    }

    void Platform::notifyPosition(const Coordinates& coordinates) {
        if (bonus != nullptr) {
            Coordinates bonusCoordinates = coordinates;
            bonusCoordinates.setY(coordinates.getY() - bonus->getMBonus()->getRadius());
            bonus->setPosition(bonusCoordinates);
        }
        this->setPosition(coordinates);
        mPlatform->setPosition(coordinates.getX(), coordinates.getY());
    }

    Platform::~Platform() {
        mPlatform = nullptr;
    }

    const std::shared_ptr<Bonus> &Platform::getBonus() const {
        return bonus;
    }

    void Platform::setBonus(const std::shared_ptr<Bonus> &n_bonus) {
        Platform::bonus = n_bonus;
    }

}