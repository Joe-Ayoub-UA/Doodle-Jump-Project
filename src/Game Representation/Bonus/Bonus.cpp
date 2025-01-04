//
// Created by Joe Ayoub on 16/11/24 at 19:19.
//

#include "Bonus.h"

namespace Game_Repr {

    Bonus::Bonus() {
//        if (!mTexture.loadFromFile("textures/Bonus/Jetpack.png")) {
//            std::cerr << "Error loading bonus texture" << std::endl;
//        }
        mBonus = std::make_shared<sf::CircleShape>(20.f);
        mBonus->setScale(0.1f, 0.1f);
    }

    const std::shared_ptr<sf::CircleShape> &Bonus::getMBonus() const {
        return mBonus;
    }

    void Bonus::setMBonus(const std::shared_ptr<sf::CircleShape> &n_Bonus) {
        mBonus = n_Bonus;
    }

    std::pair<float, float> Bonus::getMDimensions() const {
        return {mDimensions.x, mDimensions.y};
    }

    const Coordinates &Bonus::getPosition() const {
        return position;
    }

    void Bonus::setPosition(const Coordinates &n_position) {
        position = n_position;
        mBonus->setPosition(position.getX(), position.getY());
    }

    void Bonus::notifyPosition(const Coordinates &coordinates) {
        setPosition(coordinates);
    }

    Bonus::~Bonus() = default;
}