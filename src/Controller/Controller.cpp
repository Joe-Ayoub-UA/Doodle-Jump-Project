//
// Created by Joe Ayoub on 16/11/24 at 20:04.
//

#include "Controller.h"

Controller::Controller() {std::make_shared<Controller>(*this);}

void Controller::movePlayerRight() {
    world->getMPlayer()->moveRight();
}

void Controller::movePlayerLeft() {
    world->getMPlayer()->moveLeft();
}

void Controller::jumpPlayer() {
    world->getMPlayer()->jump();
}

void Controller::applyGravity() {
    world->getMPlayer()->applyGravity();
}

void Controller::movePlatformRight(std::shared_ptr<Logic_Library::Platform>& platform) {
    world->getMPlatform(platform)->moveRight();
}

void Controller::movePlatformLeft(std::shared_ptr<Logic_Library::Platform>& platform) {
    world->getMPlatform(platform)->moveLeft();
}

void Controller::movePlatformUp(std::shared_ptr<Logic_Library::Platform>& platform) {
    world->getMPlatform(platform)->moveUp();
}

void Controller::movePlatformDown(std::shared_ptr<Logic_Library::Platform>& platform) {
    world->getMPlatform(platform)->moveDown();
}

void Controller::moveBGTileUp(std::shared_ptr<Logic_Library::BG_Tile>& bgTile) {
//    world->getMBGTile(bgTile)->moveUp();
}

void Controller::moveBGTileDown(std::shared_ptr<Logic_Library::BG_Tile>& bgTile) {
//    world->getMBGTile(bgTile)->moveDown();
}



Controller::~Controller() {

}
