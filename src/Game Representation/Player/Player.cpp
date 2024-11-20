//
// Created by Joe Ayoub on 16/11/24 at 19:16.
//

#include "Player.h"

Game_Repr::Player::Player() {
    mPlayer->setRadius(40.f);
    mPlayer->setPosition(100.f, 100.f);
    mPlayer->setFillColor(sf::Color::Yellow);
}
