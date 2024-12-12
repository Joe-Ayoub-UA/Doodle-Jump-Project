//
// Created by Joe Ayoub on 16/11/24 at 19:17.
//

#include "Platform.h"

namespace Game_Repr {
    Platform::Platform() : mPlatform(std::make_shared<sf::RectangleShape>(sf::Vector2f(100.f, 100.f))) {
        mPlatform->setPosition(100.f, 100.f);
        mPlatform->setFillColor(sf::Color::Red);
    }
} // Game_Repr