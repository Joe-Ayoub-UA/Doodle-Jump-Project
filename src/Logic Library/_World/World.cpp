//
// Created by Joe Ayoub on 14/11/24 at 15:21.
//

#include "World.h"
#include "../../Game Representation/Player/Player.h"

World::World() : CF(std::make_shared<Concrete_Factory>()) {
    setupWorld();
}

void World::createPlayer() {
    mPlayer = CF->createPlayer();
}

void World::createPlatform() {
    Coordinates coordinates = Random::getInstance().generateCoor();
    mPlatforms.push_back(CF->createPLatform("normal", coordinates.getX(), coordinates.getY()));
}

Logic_Library::Platform World::findLowestPlatform() {
    Logic_Library::Platform lowestPlatform;
//    Logic_Library::Platform lowestPlatform = *mPlatforms[0];
    for (auto &platform : mPlatforms) {
//        if (platform->getPosition().second > lowestPlatform.getPosition().second) {
//            lowestPlatform = *platform;
//        }
        if (platform->getY() > lowestPlatform.getY()) {
            lowestPlatform = *platform;
        }
    }
    return lowestPlatform;
}

Logic_Library::Platform World::findHighestPlatform() {
    Logic_Library::Platform highestPlatform;
    for (auto &platform : mPlatforms) {
        if (platform->getY() < highestPlatform.getY()) {
            highestPlatform = *platform;
        }
    }
    return highestPlatform;
}

void World::removePlatform(const std::shared_ptr<Logic_Library::Platform>& platform) {
    mPlatforms.erase(std::remove(mPlatforms.begin(), mPlatforms.end(), platform), mPlatforms.end());
}

void World::setupWorld() {
    createPlayer();
}
