//
// Created by Joe Ayoub on 23/12/24 at 17:02.
//

#include "Game.h"

Game::Game() : mWindow(std::make_unique<sf::RenderWindow>(sf::VideoMode(Config::windowWidth, Config::windowHeight), "Doodle Jump")), mController(std::make_shared<Controller>()) {
    this->gameInit();
    this->render();
}
//TODO implement this in the right way
void Game::gameInit() {
    std::shared_ptr<World> world = CF->createWorld();
    mController->setWorld(world);
    mPlayer = world->getMPlayer()->getObserver();

    // Create the platforms: een beetje gelijkaardig aan die van boven, de vector van platforms komt van de world
    for (const std::shared_ptr<Logic_Library::Platform>& i: world->getMPlatforms()) {
        std::cout << i->getObserver()->getPosition().getX() << " " << i->getObserver()->getPosition().getY() << std::endl;
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
    mText.setColor(sf::Color::Black);

    if (!mHighScoreFont.loadFromFile("/home/s0230501/CLionProjects/AP_Project_DoodleJump/2024-project-Joe-Ayoub-UA/textures/Fonts/Arial.ttf")) {
        std::cout << "Font not loaded" << std::endl;
    }
    mHighScoreText.setFont(mHighScoreFont);
    mHighScoreText.setString("Highscore: ");
    mHighScoreText.setCharacterSize(24);
    mHighScoreText.setFillColor(sf::Color::White);
    mHighScoreText.setStyle(sf::Text::Bold);
    mHighScoreText.setPosition(0, 30);
    mHighScoreText.setColor(sf::Color::Black);

    mController->jumpPlayer();
    mController->jumpPlayer();
}

void Game::render() {
    // Clear the window
    mWindow->clear(sf::Color::White);

    // Draw the entities (player, platforms, BG_Tiles, bonuses)
    for (const std::shared_ptr<Game_Repr::Platform>& i: mPlatforms) {
        mWindow->draw(*i->getMPlatform());
    }
    mWindow->draw(*mPlayer->getMPlayer());
    mWindow->draw(mText);
    mWindow->draw(mHighScoreText);
    mWindow->display();
}

void Game::processEvents() {
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

void Game::update() {
    if (mController->checkEndGame()) {
        mController->freezeWorld();
    }
    else {
        if (mKeyStates[sf::Keyboard::D] || mKeyStates[sf::Keyboard::Right]) {
            mController->movePlayerRight();
        }
        if (mKeyStates[sf::Keyboard::A] || mKeyStates[sf::Keyboard::Left]) {
            mController->movePlayerLeft();
        }
        if (mKeyStates[sf::Keyboard::Space] || mKeyStates[sf::Keyboard::Up]) {
            mController->jumpPlayer();
        }
        if (mKeyStates[sf::Keyboard::F]) {
            mController->freezeWorld();
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

        static bool checkpointReached = false;
        if (Score::getInstance().getMScore() > 0 and Score::getInstance().getMScore() % 10000 < 60 and !checkpointReached) {
            Config::amountOfPlatforms--;
            std::cout << "Checkpoint reached" << std::endl;
            checkpointReached = true;
        } else if (Score::getInstance().getMScore() % 5000 >= 60) {checkpointReached = false;}

        mHighScoreText.setString("Highscore: "+std::to_string(Score::getInstance().getHighScore()));
    }
}

void Game::handlePlayerInputs(sf::Keyboard::Key key, bool isPressed) {
    mKeyStates[key] = isPressed;
}

void Game::sleep(float time) {
    Stopwatch& stopwatch = Stopwatch::getInstance();
    stopwatch.start();
    while (true) {
        auto elapsedTime = stopwatch.getElapsedTime();
        if (elapsedTime >= time) {
            stopwatch.stop();
            break;
        }
    }
    std::this_thread::sleep_for(std::chrono::nanoseconds(1));

}

void Game::run() {
//    mStopwatch->startStopwatch;
    sf::Clock clock;
    while (mWindow->isOpen()) {

        Stopwatch::getInstance().start();
//        sf::Time deltatime = clock.restart();
        processEvents();
//        std::cout << "Player position: " << mBonus->getPosition().getX() << ", " << mBonus->getPosition().getY() << std::endl;
        update();
        render();
        Stopwatch::getInstance().stop();
        auto timeLeft = (1.f / 60.f) - Stopwatch::getInstance().getElapsedTime();
//        std::this_thread::sleep_for(std::chrono::duration<float>(timeLeft));}
        sleep(timeLeft);
    }
}