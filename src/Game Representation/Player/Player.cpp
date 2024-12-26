//
// Created by Joe Ayoub on 16/11/24 at 19:16.
//

#include "Player.h"
namespace Game_Repr {
    Game_Repr::Player::Player() : mPlayer(std::make_shared<sf::RectangleShape>(mDimensions)) {
        mPlayer->setOrigin({mDimensions.x/2.f, mDimensions.y/2.f});
        mPlayer->setPosition((float)Config::windowWidth/2, (float)Config::windowHeight/2);
        mPlayer->setFillColor(sf::Color::Yellow);
//        mPlayer->setOrigin(mPlayer->getRadius(),mPlayer->getRadius());
        auto posX = static_cast<float>((float)Config::windowWidth/2);
        auto posY = static_cast<float>((float)Config::windowHeight/2);
        mPlayer->setPosition(posX, posY);
        mPlayer->setFillColor(sf::Color::Yellow);
    }

    const std::shared_ptr<sf::RectangleShape> &Game_Repr::Player::getMPlayer() const {
        return mPlayer;
    }

    void Game_Repr::Player::setMPlayer(const std::shared_ptr<sf::RectangleShape> &mPlayer) {
        Player::mPlayer = std::make_shared<sf::RectangleShape>();
    }

    Player::~Player() {
        mPlayer = nullptr;
    }

    Player::Player(int radius, const Coordinates &position, const sf::Color &color) : radius(radius),
                                                                                                  position(position),
                                                                                                  color(color) {
        mPlayer = std::make_shared<sf::RectangleShape>(sf::Vector2(50.f,50.f));
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

    std::pair<float,float> Player::getMDimensions() const {
        return std::make_pair(mDimensions.x, mDimensions.y);
    }
}