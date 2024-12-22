//
// Created by Joe Ayoub on 16/11/24 at 19:16.
//

#include "Player.h"
namespace Game_Repr {
    Game_Repr::Player::Player() : mPlayer(std::make_shared<sf::CircleShape>(40.f)) {
        mPlayer->setPosition(100.f, 100.f);
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

    Player::Player(int radius, const std::pair<float, float> &position, const sf::Color &color) : radius(radius),
                                                                                                  position(position),
                                                                                                  color(color) {
        mPlayer = std::make_shared<sf::CircleShape>(radius);
        mPlayer->setPosition(position.first, position.second);
        mPlayer->setFillColor(color);
    }
}