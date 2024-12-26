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

std::shared_ptr<Logic_Library::Platform> World::getMPlatform(std::shared_ptr<Logic_Library::Platform> &platform) {
    for (const auto &i:mPlatforms) {
        if (platform == i) {
            return i;
        }
    }
    return nullptr;
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

std::shared_ptr<Logic_Library::BG_Tile> World::getMBGTile(std::shared_ptr<Logic_Library::BG_Tile> &bgTile) {
    for (const auto &i:mBG_Tiles) {
        if (bgTile == i) {
            return i;
        }
    }
    return nullptr;
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
    Coordinates coordinates = Random::getInstance().generateCoor();
    std::cout << "Left: " << coordinates.getX()-Config::platformWidth/2.f << "\tRight: " << coordinates.getX()+Config::platformWidth/2.f << std::endl;
    if (checkValidPlatform(coordinates)) {
        mPlatforms.push_back(CF->createPlatform(coordinates.getX(), coordinates.getY()));
        return true;
    }
    return false;
}

void World::createBGTile() {
    mBG_Tiles.push_back(CF->createBGTile());
}

void World::createBonus() {
    mBonuses.push_back(CF->createBonus());
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

bool World::checkCollision() {
    ///@todo: Implement collision detection
    if (this->getMPlayer()->getVerticalSpeed() < 0) {
        std::cout << "Vertical Speed is negative, no collision" << std::endl;
        return false;
    }
    else {
        for (const auto& platform : mPlatforms) {
            if (this->getMPlayer()->getObserver()->getGlobalBounds().intersects(platform->getObserver()->getGlobalBounds())) {
                float playerBottom = this->getMPlayer()->getObserver()->getGlobalBounds().top + this->getMPlayer()->getObserver()->getGlobalBounds().height;
                float platformTop = platform->getObserver()->getGlobalBounds().top;
                std::cout << "Collision detected" << std::endl;
                if (playerBottom >= platformTop) {
                    return true;
                }
            }
        }
    }
//    for (const auto& platform : mPlatforms) {
//        if (mPlayer->getMPlayer()->getGlobalBounds().intersects(platform->getMPlatform()->getGlobalBounds())) {
//            return true;
//        }
//    }
    return false;
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
