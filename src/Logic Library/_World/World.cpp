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

bool World::createPlatform(const std::optional<Coordinates>& coordinate) {
    Coordinates coordinates;
    if (coordinate.has_value()) {
        coordinates = coordinate.value();
    }
    else {
        coordinates = Random::getInstance().generateCoor();
    }
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
    Logic_Library::Platform lowestPlatform = *mPlatforms[0];
    for (auto &platform : mPlatforms) {
        if (platform->getObserver()->getPosition().getY() > lowestPlatform.getObserver()->getPosition().getY()) {
            lowestPlatform = *platform;
        }
    }
    return lowestPlatform;
}

Logic_Library::Platform World::findHighestPlatform() {
    Logic_Library::Platform highestPlatform = *mPlatforms[0];
    for (auto &platform : mPlatforms) {
        if (platform->getObserver()->getPosition().getY() < highestPlatform.getObserver()->getPosition().getY()) {
            highestPlatform = *platform;
        }
    }
    return highestPlatform;
}

bool World::checkValidPlatform(const Coordinates& coordinate) {
    ///@todo FIX THIS, PROBLEM LIES SOMEWHERE HERE
    const float minDistance = Random::getInstance().randomFloat(Config::minPlatformDistance.first, Config::minPlatformDistance.second);
    if (coordinate.getX() + Config::platformWidth/2 > Config::windowWidth or coordinate.getX() < 0) {
        return false;
    }
    if (coordinate.getY() + Config::platformHeight / 2 > Config::windowHeight or coordinate.getY() - Config::platformHeight / 2 < -Config::platformPositionOffset) {
        return false;
    }

    // Check if the new platform overlaps or is too close to existing platforms
    for (const auto& platform : mPlatforms) {
        float dx = platform->getObserver()->getPosition().getX() - coordinate.getX();
        float dy = platform->getObserver()->getPosition().getY() - coordinate.getY();
        float distance = std::sqrt((dx * dx) + (dy * dy));

        if (distance < minDistance) {
            return false;
        }
        // Check for overlap considering platform dimensions
        if (std::abs(dx) < Config::platformWidth && std::abs(dy) < Config::platformHeight) {
            return false;
        }
    }
    return true;
}

bool World::checkCollision() {
    ///@todo: Fix collision detection, because now the jump is happening when the top of the player is colliding with the platform, which is not correct
    if (this->getMPlayer()->getVerticalSpeed() <= 0) {
        return false;
    }
    else {
        Coordinates playerCoordinates = this->getMPlayer()->getObserver()->getPosition();
        std::pair<float, float> playerDimensions = this->getMPlayer()->getObserver()->getMDimensions();
        playerCoordinates.setY(playerCoordinates.getY() + playerDimensions.second);
        for (const auto& platform : mPlatforms) {
            if (this->getMPlayer()->getObserver()->getGlobalBounds().intersects(platform->getObserver()->getGlobalBounds())) {
                float playerBottom = this->getMPlayer()->getObserver()->getGlobalBounds().top + this->getMPlayer()->getObserver()->getGlobalBounds().height;
                float platformTop = platform->getObserver()->getGlobalBounds().top;
                if (playerBottom >= platformTop) {
//                    std::cout << "Collision detected" << std::endl;
                    if (platform->getPType() == Enums::TEMPORARY) {
                        removePlatform(platform);
                    }
                    return true;
                }
            }
//            Coordinates platformCoordinates = platform->getObserver()->getPosition();
//            if (playerCoordinates.getX() + playerDimensions.first > platformCoordinates.getX() or playerCoordinates.getX() < platformCoordinates.getX() + Config::platformWidth) {
//                std::cout << "Player bottom: " << playerCoordinates.getY() + playerDimensions.second << "\tPlatform top: " << platformCoordinates.getY() << std::endl;
//                if ((playerCoordinates.getY() + playerDimensions.second) < playerCoordinates.getY()) {
//                    return true;
//                }
//            }
//            if (playerCoordinates.getX() > platformCoordinates.getX() and playerCoordinates.getX() < platformCoordinates.getX() + Config::platformWidth) {
//                std::cout << "Player bottom: " << playerCoordinates.getY() + playerDimensions.second << "\tPlatform top: " << platformCoordinates.getY() << std::endl;
//                if ((playerCoordinates.getY() + playerDimensions.second) < playerCoordinates.getY()) {
//                    return true;
//                }
//            }
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
    std::vector<std::shared_ptr<Logic_Library::Platform>> newPlatforms{};
    for (auto &i:mPlatforms) {
        if (i->getPosition() == platform->getPosition()) {continue;}
        else {
            newPlatforms.push_back(i);
        }
    }
    mPlatforms = newPlatforms;
}

void World::movePlatformsDown(float moveDownDistance) {
    for (auto &platform : mPlatforms) {
        platform->fixTooHigh(moveDownDistance);
    }
}

void World::updatePlatforms() {
    for (auto &platform : mPlatforms) {
        if (platform->getPType() == Enums::STATIC) {continue;}
        else if (platform->getPType() == Enums::HORIZONTAL) {
            if (platform->isGoingLeft()) {
                platform->moveLeft();
            }
            else {
                platform->moveRight();
            }
        }
        else if (platform->getPType() == Enums::VERTICAL) {
            if (platform->isGoingUp()) {
                platform->moveUp();
            }
            else {
                platform->moveDown();
            }
        }
    }
}

bool World::isPlatformNeeded() {
    Logic_Library::Platform highestPlatform = this->findHighestPlatform();
    if (highestPlatform.getObserver()->getPosition().getY() >= 0) {
        return true;
    }
    return false;
}

bool World::isPlatformNotNeeded() {
    Logic_Library::Platform lowestPlatform = this->findLowestPlatform();
    if (lowestPlatform.getPosition().getY() > Config::windowHeight) {
        return true;
    }
    return false;
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
    if (isPlatformNeeded()) {
//        std::cout << mPlatforms.size() << std::endl;
        float x = Random::getInstance().randomFloat(0, Config::windowWidth);
        if (mPlatforms.size()+1<=Config::amountOfPlatforms) {
            float y = Random::getInstance().randomFloat(-Config::platformPositionOffset, 0);
            Coordinates coordinates(x, y);
            std::optional<Coordinates> optCoordinates = std::make_optional<Coordinates>(coordinates);
            createPlatform(optCoordinates);
        }
    }
    ///@todo checkValidPlatform()
    if (isPlatformNotNeeded()) {
        removePlatform(std::make_shared<Logic_Library::Platform>(findLowestPlatform()));
    }


    // Check if player is too high
    Coordinates playerCoordinates = this->getMPlayer()->getObserver()->getPosition();
    if (playerCoordinates.getY() < (float)Config::windowHeight / 2) {
//        std::cout << "Player is too high" << std::endl;
        float moveDownDistance = (float)Config::windowHeight / 2 - playerCoordinates.getY();
        Coordinates newCoordinates(playerCoordinates.getX(), (float)Config::windowHeight / 2);
        this->getMPlayer()->getObserver()->notifyPosition(newCoordinates);
        this->movePlatformsDown(moveDownDistance);
        int score = std::floor((float)Score::getInstance().getMScore() + moveDownDistance);
        Score::getInstance().setMScore(score);
        Score::getInstance().updateHighScore(score);
        std::cout << "Score: " << Score::getInstance().getMScore() << std::endl;
    }
    this->updatePlatforms();


}
