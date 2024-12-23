//

#include "Concrete_Factory.h"
#include "../../Logic Library/_World/World.h"

//
// Created by Joe Ayoub on 14/11/24 at 16:06.

std::shared_ptr<Logic_Library::Player> Concrete_Factory::createPlayer() {
    std::shared_ptr<Logic_Library::Player> player = std::make_shared<Logic_Library::Player>();
    std::shared_ptr<Game_Repr::Player> player_view = std::make_shared<Game_Repr::Player>();
    player->assignObserver(player_view);
    return player;
}

std::shared_ptr<Logic_Library::Platform> Concrete_Factory::createPlatform(float x, float y) {
    std::shared_ptr<Logic_Library::Platform> platform = std::make_shared<Logic_Library::Platform>(x,y);
    std::shared_ptr<Game_Repr::Platform> platform_view = std::make_shared<Game_Repr::Platform>();
    platform->assignObserver(platform_view);
    return platform;
}

std::shared_ptr<Logic_Library::BG_Tile> Concrete_Factory::createBG_Tile() {
    return nullptr;
}

std::shared_ptr<Logic_Library::Bonus> Concrete_Factory::createBonus() {
    return nullptr;
}

std::shared_ptr<World> Concrete_Factory::createWorld() {
    std::shared_ptr<World> world(new World());
    return world;
}

void Concrete_Factory::assignObserver(std::shared_ptr<Observer> newObserver) {
    this->observer = std::move(newObserver);
}

void Concrete_Factory::deleteObserver() {
    this->observer = nullptr;
}

void Concrete_Factory::notifyObserver() {
    observer->update();
}
