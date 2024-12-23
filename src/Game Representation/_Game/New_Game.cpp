//
// Created by Joe Ayoub on 23/12/24 at 17:02.
//

#include "New_Game.h"

New_Game::New_Game() : mWindow(std::make_unique<sf::RenderWindow>(sf::VideoMode(Config::windowWidth, Config::windowHeight), "Doodle Jump")) {
    this->gameInit();
}

void New_Game::gameInit() {
    Concrete_Factory CF;

}
