//
// Created by Joe Ayoub on 16/11/24 at 19:16.
//

#include "Player.h"
namespace Game_Repr {
    Game_Repr::Player::Player() : mPlayer(std::make_shared<sf::Sprite>()), mHitboxDebug(std::make_shared<sf::RectangleShape>()) {
        auto posX = static_cast<float>((float)Config::windowWidth/2);
        auto posY = static_cast<float>((float)Config::windowHeight);
        if (!mTexture.loadFromFile("../textures/Doodle/NinjaDoodle.png")) {
            throw std::runtime_error("Error loading player texture");
        }
        else {
            // Get the size of the texture
            sf::Vector2u textureSize = mTexture.getSize();
            float scaleX = 50.f / textureSize.x;
            float scaleY = 50.f / textureSize.y;

            // Set the texture, scale and position of the player
            mPlayer->setTexture(mTexture);
            mPlayer->setScale(scaleX*2, (scaleY*2));
            mPlayer->setPosition(posX, posY);

            // Update mDimensions based on the texture size and scale
            mDimensions.x = (float)textureSize.x * mPlayer->getScale().x;
            mDimensions.y = (float)textureSize.y * mPlayer->getScale().y;

            mHitboxDebug->setSize(sf::Vector2f(mDimensions.x, mDimensions.y));
            mHitboxDebug->setFillColor(sf::Color(255, 0, 0, 128)); // Semi-transparent red for debugging
            mHitboxDebug->setPosition(mPlayer->getPosition());
        }
    }

    const std::shared_ptr<sf::Sprite> &Game_Repr::Player::getMPlayer() const {
        return mPlayer;
    }

    void Game_Repr::Player::setMPlayer(const std::shared_ptr<sf::Sprite> &n_mPlayer) {
        Player::mPlayer = n_mPlayer;
    }

    Player::~Player() {
        mPlayer = nullptr;
    }

    const Coordinates &Player::getPosition() const {
        return position;
    }

    void Player::setPosition(const Coordinates &n_position) {
        Player::position = n_position;
    }

    void Player::notifyPosition(const Coordinates& coordinates) {
        this->setPosition(coordinates);
        mPlayer->setPosition(coordinates.getX(), coordinates.getY());
        mHitboxDebug->setPosition(coordinates.getX(), coordinates.getY());
    }

    std::pair<float,float> Player::getMDimensions() const {
        return std::make_pair(mDimensions.x, mDimensions.y);
    }

    const std::shared_ptr<sf::RectangleShape> &Player::getMHitboxDebug() const {
        return mHitboxDebug;
    }
}