//
// Created by Joe Ayoub on 16/11/24 at 20:04.
//

#include "Controller.h"

Controller::Controller() { std::make_shared<Controller>(*this); }

void Controller::movePlayerRight() { world->getMPlayer()->moveRight(); }

void Controller::movePlayerLeft() { world->getMPlayer()->moveLeft(); }

void Controller::jumpPlayer() { world->getMPlayer()->jump(); }

Controller::~Controller() {}
