//

#include "Concrete_Factory.h"
#include "../../Logic Library/_World/World.h"

//
// Created by Joe Ayoub on 14/11/24 at 16:06.

sf::Color Concrete_Factory::handleColor(Enums::PlatformType type) {
    if (Config::platformColor.at(type) == "Green") {
        return sf::Color::Green;
    }
    else if (Config::platformColor.at(type) == "Blue") {
        return {2,204,255};
    }
    else if (Config::platformColor.at(type) == "Yellow") {
        return sf::Color::Yellow;
    }
    else if (Config::platformColor.at(type) == "White") {
        return sf::Color::White;
    }
    return sf::Color::Green;
}

std::shared_ptr<Logic_Library::Player> Concrete_Factory::createPlayer() {
    std::shared_ptr<Logic_Library::Player> player = std::make_shared<Logic_Library::Player>();
    std::shared_ptr<Game_Repr::Player> player_view = std::make_shared<Game_Repr::Player>();
    player->assignObserver(player_view);
    return player;
}

std::shared_ptr<Logic_Library::Platform> Concrete_Factory::createPlatform(float x, float y) {
    std::shared_ptr<Logic_Library::Platform> platform = std::make_shared<Logic_Library::Platform>();
    std::shared_ptr<Game_Repr::Platform> platform_view = std::make_shared<Game_Repr::Platform>();
    platform_view->setPlatformPos(x,y);
    if (platform->getPType() == Enums::HORIZONTAL and x <= (float)Config::windowWidth/2) {platform->setGoingLeft(true);}
    if (platform->getPType() == Enums::VERTICAL and y >= (float)Config::windowHeight/2) {platform->setGoingUp(true);}
    platform_view->getMPlatform()->setFillColor(handleColor(platform->getPType()));
    platform->assignObserver(platform_view);
    return platform;
}

std::shared_ptr<Logic_Library::BG_Tile> Concrete_Factory::createBGTile() {
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
