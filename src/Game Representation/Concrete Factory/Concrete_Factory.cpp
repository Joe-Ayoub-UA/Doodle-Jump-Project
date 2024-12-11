//
// Created by Joe Ayoub on 14/11/24 at 16:06.
//

#include "Concrete_Factory.h"


std::shared_ptr<Game_Repr::Player> Concrete_Factory::createPlayer() {
    std::shared_ptr<Game_Repr::Player> player = std::make_shared<Game_Repr::Player>();
    return player;
}

std::shared_ptr<Game_Repr::Platform> Concrete_Factory::createPLatform(int x, int y) {
    std::shared_ptr<Game_Repr::Platform> platform = std::make_shared<Game_Repr::Platform>();
    return platform;
}
