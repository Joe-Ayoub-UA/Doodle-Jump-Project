//
// Created by Joe Ayoub on 14/11/24 at 15:21.
//

#include "World.h"

World::World() {
    auto AF = std::make_shared<Concrete_Factory>();
}

void World::createPlayer() {
    std::shared_ptr<Logic_Library::Player> player_subject = std::make_shared<Logic_Library::Player>();
//    std::shared_ptr<Game_Repr::Player> player_observer = std::make_shared<Game_Repr::Player>();
}
