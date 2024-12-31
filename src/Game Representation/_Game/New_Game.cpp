//
// Created by Joe Ayoub on 23/12/24 at 17:02.
//

#include "New_Game.h"

New_Game::New_Game() : mWindow(std::make_unique<sf::RenderWindow>(sf::VideoMode(Config::windowWidth, Config::windowHeight), "Doodle Jump")), mController(std::make_shared<Controller>()) {
    this->gameInit();
    this->render();
}
//TODO implement this in the right way
void New_Game::gameInit() {
    std::shared_ptr<World> world = CF->createWorld();
    mController->setWorld(world);
    mPlayer = world->getMPlayer()->getObserver();

    // Create the platforms: een beetje gelijkaardig aan die van boven, de vector van platforms komt van de world
    for (const std::shared_ptr<Logic_Library::Platform>& i: world->getMPlatforms()) {
        std::cout << i->getPosition().getX() << " " << i->getPosition().getY() << std::endl;
        mPlatforms.push_back(i->getObserver());
    }

    // Generating the text for the score
    if (!mFont.loadFromFile("/home/s0230501/CLionProjects/AP_Project_DoodleJump/2024-project-Joe-Ayoub-UA/textures/Fonts/Arial.ttf")) {
        std::cout << "Font not loaded" << std::endl;
    }
    mText.setFont(mFont);
    mText.setString("Score: ");
    mText.setCharacterSize(24);
    mText.setFillColor(sf::Color::White);
    mText.setStyle(sf::Text::Bold);

    if (!mHighScoreFont.loadFromFile("/home/s0230501/CLionProjects/AP_Project_DoodleJump/2024-project-Joe-Ayoub-UA/textures/Fonts/Arial.ttf")) {
        std::cout << "Font not loaded" << std::endl;
    }
    mHighScoreText.setFont(mHighScoreFont);
    mHighScoreText.setString("Highscore: ");
    mHighScoreText.setCharacterSize(24);
    mHighScoreText.setFillColor(sf::Color::White);
    mHighScoreText.setStyle(sf::Text::Bold);
    mHighScoreText.setPosition(0, 30);

    mController->jumpPlayer();
    mController->jumpPlayer();
}

void New_Game::render() {
    // Clear the window
    mWindow->clear();

    // Draw the entities (player, platforms, BG_Tiles, bonuses)
    for (const std::shared_ptr<Game_Repr::Platform>& i: mPlatforms) {
        mWindow->draw(*i->getMPlatform());
    }
    mWindow->draw(*mPlayer->getMPlayer());
    mWindow->draw(mText);
    mWindow->draw(mHighScoreText);
    mWindow->display();
}

void New_Game::processEvents() {
    sf::Event mEvent{};
    while (mWindow->pollEvent(mEvent)) {
        switch (mEvent.type) {
            case sf::Event::KeyPressed:
                handlePlayerInputs(mEvent.key.code,true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInputs(mEvent.key.code,false);
                break;
            case sf::Event::Closed:
                mWindow->close();
                break;
        }

    }
}

void New_Game::update() {
    mController->applyGravity();
    if (mKeyStates[sf::Keyboard::D] || mKeyStates[sf::Keyboard::Right]) {
        mController->movePlayerRight();
    }
    if (mKeyStates[sf::Keyboard::A] || mKeyStates[sf::Keyboard::Left]) {
        mController->movePlayerLeft();
    }
    if (mKeyStates[sf::Keyboard::Space] || mKeyStates[sf::Keyboard::Up]) {
        mController->jumpPlayer();
    }
    mController->outOfBounds();
    if (mController->checkCollision()) {
        mController->jumpPlayer();
    }
    mController->updateWorld();
    mPlatforms.clear();
    for (const std::shared_ptr<Logic_Library::Platform>& i: mController->getWorld()->getMPlatforms()) {
        mPlatforms.push_back(i->getObserver());
    }
    mText.setString("Score: "+std::to_string(Score::getInstance().getMScore()));
    mHighScoreText.setString("Highscore: "+std::to_string(Score::getInstance().getHighScore()));
}

void New_Game::handlePlayerInputs(sf::Keyboard::Key key, bool isPressed) {
    mKeyStates[key] = isPressed;
}

void New_Game::run() {
//    mStopwatch->startStopwatch;
    sf::Clock clock;
    while (mWindow->isOpen()) {

        Stopwatch::getInstance().start();
//        sf::Time deltatime = clock.restart();
        processEvents();
//        std::cout << "Player position: " << mPlayer->getPosition().getX() << ", " << mPlayer->getPosition().getY() << std::endl;
        update();
        render();
        Stopwatch::getInstance().stop();
        auto timeLeft = (1.f/60.f) - Stopwatch::getInstance().getElapsedTime();
        std::this_thread::sleep_for(std::chrono::duration<float>(timeLeft));}
}