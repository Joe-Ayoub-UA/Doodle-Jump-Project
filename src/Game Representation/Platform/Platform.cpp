//
// Created by Joe Ayoub on 16/11/24 at 19:17.
//

#include "Platform.h"

namespace Game_Repr {
    Platform::Platform() : mPlatform(std::make_shared<sf::RectangleShape>(sf::Vector2f(Config::platformWidth, Config::platformHeight))) {
        mPlatform->setOutlineThickness(1.f);
            mPlatform->setOutlineColor(sf::Color::White);
    }

    const std::shared_ptr<sf::RectangleShape> &Platform::getMPlatform() const {
        return mPlatform;
    }

    void Platform::setMPlatform(const std::shared_ptr<sf::RectangleShape> &mPlatform) {
        Platform::mPlatform = std::make_shared<sf::RectangleShape>();
    }

    const std::pair<float, float> &Platform::getPosition() const {
        return position;
    }

    void Platform::setPosition(const std::pair<float, float> &n_position) {
        Platform::position = n_position;
    }

    void Platform::setPlatformPos(float x, float y) {
        mPlatform->setPosition(x, y);
    }

    void Platform::notifyPosition(const Coordinates& coordinates) {
        mPlatform->setPosition(coordinates.getX(), coordinates.getY());
    }

    Platform::~Platform() {
        mPlatform = nullptr;
    }

}