//
// Created by Joe Ayoub on 23/12/24 at 17:02.
//

#include "New_Game.h"

New_Game::New_Game() : mWindow(std::make_unique<sf::RenderWindow>(sf::VideoMode(Config::windowWidth, Config::windowHeight), "Doodle Jump")) {
    this->gameInit();
    this->render();
}
//TODO implement this in the right way
void New_Game::gameInit() {
    std::shared_ptr<World> world = CF->createWorld();
    mPlayer = world->getMPlayer()->getObserver();

    // Create the platforms: een beetje gelijkaardig aan die van boven, de vector van platforms komt van de world
    for (const std::shared_ptr<Logic_Library::Platform>& i: world->getMPlatforms()) {
        mPlatforms.push_back(i->getObserver());
    }
}

void New_Game::render() {
    mWindow->clear();
    mWindow->draw(*mPlayer->getMPlayer());
    for (const std::shared_ptr<Game_Repr::Platform>& i: mPlatforms) {
        mWindow->draw(*i->getMPlatform());
    }
    mWindow->display();
}

void New_Game::processEvents() {
    sf::Event event;
    while (mWindow->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            mWindow->close();
        }
    }
}

void New_Game::update(sf::Time deltatime) {
    // Update game state here
}

void New_Game::run() {
//    mStopwatch->startStopwatch;
    sf::Clock clock;
    while (mWindow->isOpen()) {

        sf::Time deltatime = clock.restart();
        processEvents();
//        update(deltatime);
        render();
    }
}