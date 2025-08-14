//

#include "Concrete_Factory.h"
#include "../../Logic Library/_World/World.h"

//
// Created by Joe Ayoub on 14/11/24 at 16:06.

sf::Color Concrete_Factory::handlePlatformColor(Enums::PlatformType type) {
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

sf::Color Concrete_Factory::handleBonusColor(Enums::BonusType type) {
    if (Config::bonusTexture.at(type) == "Red") {
//        std::cout << "Red bonus" << std::endl;
        return {255, 0, 0,128}; // Red color for Jetpack bonus
    }
    else if (Config::bonusTexture.at(type) == "Blue") {
//        std::cout << "Blue bonus" << std::endl;
        return {0, 0, 255, 128}; // Blue color for Spring bonus
    }
    return sf::Color::Transparent; // No bonus
}

std::shared_ptr<Logic_Library::Player> Concrete_Factory::createPlayer() {
    std::shared_ptr<Logic_Library::Player> player = std::make_shared<Logic_Library::Player>();
    std::shared_ptr<Game_Repr::Player> player_view = std::make_shared<Game_Repr::Player>();
    player->assignObserver(player_view);
    return player;
}

std::shared_ptr<Logic_Library::Platform> Concrete_Factory::createPlatform(Coordinates coordinate) {
//    std::cout << "Creating platform at coordinates: " << coordinate.getX() << ", " << coordinate.getY() << std::endl;
    std::shared_ptr<Logic_Library::Platform> platform = std::make_shared<Logic_Library::Platform>();

    std::shared_ptr<Game_Repr::Platform> platform_view = std::make_shared<Game_Repr::Platform>();
    platform_view->setPlatformPos(coordinate.getX(), coordinate.getY());
    if (platform->getPType() == Enums::HORIZONTAL and coordinate.getX() <= (float)Config::windowWidth/2) {platform->setGoingLeft(Random::getInstance().randomBool());}
    if (platform->getPType() == Enums::VERTICAL and coordinate.getY() >= (float)Config::windowHeight/2) {platform->setGoingUp(Random::getInstance().randomBool());}
    platform_view->getMPlatform()->setFillColor(handlePlatformColor(platform->getPType()));

    if (platform->getHasBonus() and platform->getBonus() != nullptr) {
        // Use the existing bonus
        std::shared_ptr<Logic_Library::Bonus> bonus = platform->getBonus();
        std::shared_ptr<Game_Repr::Bonus> bonus_view = std::make_shared<Game_Repr::Bonus>(bonus->getBType());

        // Set color based on bonus type
        bonus_view->getMBonus()->setFillColor(handleBonusColor(bonus->getBType()));

        // Calculate the center position of the platform
        float bonusPosX = coordinate.getX() + (Config::platformWidth / 2);
        float bonusPosY = coordinate.getY() - bonus_view->getMBonus()->getRadius();
        // Assign the bonus view to the bonus logic
        bonus->assignObserver(bonus_view);

        // Position the bonus
        bonus->notifyPosition(Coordinates(bonusPosX, bonusPosY));

        bonus_view->setPosition(Coordinates(bonusPosX, bonusPosY));

        platform_view->setBonus(bonus_view);
    }

    platform->assignObserver(platform_view);
//    std::cout << "Platform created at coordinates: " << coordinate.getX() << ", " << coordinate.getY() << std::endl << std::endl;
    return platform;
}

std::shared_ptr<Logic_Library::BG_Tile> Concrete_Factory::createBGTile() {
    return nullptr;
}

std::shared_ptr<Logic_Library::Bonus> Concrete_Factory::createBonus() {return nullptr;}


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
