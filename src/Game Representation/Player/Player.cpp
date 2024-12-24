//
// Created by Joe Ayoub on 16/11/24 at 19:16.
//

#include "Player.h"
namespace Game_Repr {
    Game_Repr::Player::Player() : mPlayer(std::make_shared<sf::CircleShape>(40.f)) {
        mPlayer->setOrigin(mPlayer->getRadius(),mPlayer->getRadius());
        auto posX = static_cast<float>((float)Config::windowWidth/2);
        auto posY = static_cast<float>((float)Config::windowHeight/2);
        mPlayer->setPosition(posX, posY);
        mPlayer->setFillColor(sf::Color::Yellow);
    }

    const std::shared_ptr<sf::CircleShape> &Game_Repr::Player::getMPlayer() const {
        return mPlayer;
    }

    void Game_Repr::Player::setMPlayer(const std::shared_ptr<sf::CircleShape> &mPlayer) {
        Player::mPlayer = std::make_shared<sf::CircleShape>();
    }

    Player::~Player() {
        mPlayer = nullptr;
    }

    Player::Player(int radius, const Coordinates &position, const sf::Color &color) : radius(radius),
                                                                                                  position(position),
                                                                                                  color(color) {
        mPlayer = std::make_shared<sf::CircleShape>(radius);
        mPlayer->setPosition(position.getX(), position.getY());
        mPlayer->setFillColor(color);
    }

    const Coordinates &Player::getPosition() const {
        return position;
    }

    void Player::setPosition(const Coordinates &n_position) {
        Player::position = n_position;
    }

    void Player::notifyPosition(const Coordinates& coordinates) {
        mPlayer->setPosition(coordinates.getX(), coordinates.getY());
    }
}