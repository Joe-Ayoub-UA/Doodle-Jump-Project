//

#include "World.h"
#include "../../Game Representation/Player/Player.h"

//
// Created by Joe Ayoub on 14/11/24 at 15:21.
const std::shared_ptr<Concrete_Factory> &World::getCf() const {
    return CF;
}

void World::setCf(const std::shared_ptr<Concrete_Factory> &cf) {
    CF = cf;
}

const std::shared_ptr<Logic_Library::Player> &World::getMPlayer() const {
    return mPlayer;
}

void World::setMPlayer(const std::shared_ptr<Logic_Library::Player> &mPlayer) {
    World::mPlayer = mPlayer;
}

const std::vector<std::shared_ptr<Logic_Library::Platform>> &World::getMPlatforms() const {
    return mPlatforms;
}

void World::setMPlatforms(const std::vector<std::shared_ptr<Logic_Library::Platform>> &mPlatforms) {
    World::mPlatforms = mPlatforms;
}

const std::vector<std::shared_ptr<Logic_Library::BG_Tile>> &World::getMbgTiles() const {
    return mBG_Tiles;
}

void World::setMbgTiles(const std::vector<std::shared_ptr<Logic_Library::BG_Tile>> &mBgTiles) {
    mBG_Tiles = mBgTiles;
}

const std::vector<std::shared_ptr<Logic_Library::Bonus>> &World::getMBonuses() const {
    return mBonuses;
}

void World::setMBonuses(const std::vector<std::shared_ptr<Logic_Library::Bonus>> &mBonuses) {
    World::mBonuses = mBonuses;
}

World::World() : CF(std::make_shared<Concrete_Factory>()) {
    setupWorld();
}

void World::createPlayer() {
    mPlayer = CF->createPlayer();
}

bool World::createPlatform() {
//    Coordinates coordinates = Random::getInstance().generateCoor();
//    auto rand1 = (float)Random::getInstance().randomInt(-20,20);
//    auto rand2 = (float)Random::getInstance().randomInt(-20,20);
//    Random::getInstance().setXRange(std::make_pair(coordinates.getX() + rand1, coordinates.getX() + rand2));
//    Random::getInstance().setYRange(std::make_pair(coordinates.getY() + rand1, coordinates.getY() + rand2));
    Coordinates coordinates = Random::getInstance().generateCoor();
    std::cout << "Left: " << coordinates.getX()-Config::platformWidth/2.f << "\tRight: " << coordinates.getX()+Config::platformWidth/2.f << std::endl;
    if (checkValidPlatform(coordinates)) {
        mPlatforms.push_back(CF->createPlatform(coordinates.getX(), coordinates.getY()));
        return true;
    }
    return false;
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

bool World::checkValidPlatform(const Coordinates& coordinate) {
    bool validPosition = false;
    const float minDistance = Random::getInstance().randomFloat(Config::minPlatformDistance.first, Config::minPlatformDistance.second);

// Try generating coordinate until a valid position is found
    do {
//        float x = std::clamp(coordinate.getX(), Config::platformWidth / 2.0f, Config::windowWidth - Config::platformWidth / 2.0f);
//        float y = std::clamp(coordinate.getY(), Config::platformHeight / 2.0f, Config::windowHeight - Config::platformHeight / 2.0f);
        if (coordinate.getX() + Config::platformWidth / 2 > Config::windowWidth or coordinate.getX() - Config::platformWidth / 2 < 0) {
            return false;
//            coordinate.setX(Config::windowWidth - Config::platformWidth / 2);
        }
        if (coordinate.getY() + Config::platformHeight / 2 > Config::windowHeight or coordinate.getY() - Config::platformHeight / 2 < 0) {
            return false;
        }

//        coordinate.setX(x);
//        coordinate.setY(y);

        validPosition = true;

        // Check if the new platform overlaps or is too close to existing platforms
        for (const auto& platform : mPlatforms) {
            float dx = platform->getX() - coordinate.getX();
            float dy = platform->getY() - coordinate.getY();
            float distance = std::sqrt(dx * dx + dy * dy);

            if (distance < minDistance) {
                return false;
                validPosition = false;
                break;
            }

            // Check for overlap considering platform dimensions
            if (std::abs(dx) < Config::platformWidth && std::abs(dy) < Config::platformHeight) {
                return false;
                validPosition = false;
                break;
            }
        }
    } while (!validPosition);
    return true;
}

void World::removePlatform(const std::shared_ptr<Logic_Library::Platform>& platform) {
    mPlatforms.erase(std::remove(mPlatforms.begin(), mPlatforms.end(), platform), mPlatforms.end());
}

bool World::isPlatformNeeded() {
    return this->findHighestPlatform().getY() < Config::windowHeight;
}

void World::setupWorld() {
    createPlayer();

    mPlatforms.clear();
    for (int i = 0; i < Config::amountOfPlatforms; i++) {
        if (!createPlatform()) {
            i--;
        }
    }

}

void World::updateWorld() {
//    if (isPlatformNeeded()) {
//        createPlatform();
//    }
}
