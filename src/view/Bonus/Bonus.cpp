//
// Created by Joe Ayoub on 16/11/24 at 19:19.
//

#include "Bonus.h"

namespace Game_Repr {

Bonus::Bonus(Enums::BonusType bonusType) {
    //        if (!mTexture.loadFromFile("../textures/Bonuses/Jetpack.png")) {
    //            std::cerr << "Error loading jetpack texture" << std::endl;
    //        }
    //        if (!mTexture.loadFromFile("../textures/Bonuses/Spring.png")) {
    //            std::cerr << "Error loading spring texture" << std::endl;
    //        }
    // Initialize the bonus shape and sprite
    mBonusTexture = std::make_shared<sf::Texture>();
    mBonusSprite = std::make_shared<sf::Sprite>();
    mBonus = std::make_shared<sf::CircleShape>(20.f);
    switch (bonusType) {
    case Enums::BonusType::JETPACK:
        if (!mBonusTexture->loadFromFile("../textures/Bonuses/Jetpack.png")) {
            throw std::runtime_error("Error loading jetpack texture");
        }
        mBonusSprite->setTexture(*mBonusTexture);
        break;
    case Enums::BonusType::SPRING:
        if (!mBonusTexture->loadFromFile("../textures/Bonuses/Spring.png")) {
            throw std::runtime_error("Error loading spring texture");
        }
        mBonusSprite->setTexture(*mBonusTexture);
        break;
    default:
        std::cerr << "Unknown bonus type" << std::endl;
    }
    mBonusSprite->setOrigin(mBonusTexture->getSize().x / 2, mBonusTexture->getSize().y / 2);
    float scale = (20.f * 2) / std::max(mBonusTexture->getSize().x, mBonusTexture->getSize().y);
    mBonusSprite->setScale(scale, scale); // Adjust scale as needed

    mBonus->setFillColor(sf::Color::Transparent);
    mBonus->setOrigin(mBonus->getRadius(), mBonus->getRadius()); // Set origin to center of circle
}

const std::shared_ptr<sf::CircleShape>& Bonus::getMBonus() const { return mBonus; }

void Bonus::setMBonus(const std::shared_ptr<sf::CircleShape>& n_Bonus) { mBonus = n_Bonus; }

std::pair<float, float> Bonus::getMDimensions() const { return {mDimensions.x, mDimensions.y}; }

const Coordinates& Bonus::getPosition() const { return position; }

void Bonus::setPosition(const Coordinates& n_position) {
    position = n_position;
    mBonus->setPosition(position.getX(), position.getY());
    mBonusSprite->setPosition(position.getX(), position.getY());
}

void Bonus::notifyPosition(const Coordinates& coordinates) { setPosition(coordinates); }

const std::shared_ptr<sf::Sprite>& Bonus::getMBonusSprite() const { return mBonusSprite; }

Bonus::~Bonus() = default;
} // namespace Game_Repr