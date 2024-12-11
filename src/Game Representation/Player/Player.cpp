//
// Created by Joe Ayoub on 16/11/24 at 19:16.
//

#include "Player.h"

Game_Repr::Player::Player() : mPlayer(std::make_shared<sf::CircleShape>(40.f)) {
    mPlayer->setRadius(40.f);
    mPlayer->setPosition(100.f, 100.f);
    mPlayer->setFillColor(sf::Color::Yellow);
}

const std::shared_ptr<sf::CircleShape> &Game_Repr::Player::getMPlayer() const {
    return mPlayer;
}

void Game_Repr::Player::setMPlayer(const std::shared_ptr<sf::CircleShape> &mPlayer) {
    Player::mPlayer = std::make_shared<sf::CircleShape>();
}
