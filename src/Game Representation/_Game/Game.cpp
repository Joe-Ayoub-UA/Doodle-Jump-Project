//
// Created by Joe Ayoub on 23/12/24 at 17:02.
//

#include "Game.h"

Game::Game() : mWindow(std::make_unique<sf::RenderWindow>(sf::VideoMode(Config::windowWidth, Config::windowHeight), "Doodle Jump")), mController(std::make_shared<Controller>()) {
    std::cout << Config::maxJumpHeight << std::endl;
    this->gameInit();
    this->render();
}
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
    if (!mFont.loadFromFile("../textures/Fonts/Arial.ttf")) {
        throw std::runtime_error("Font not loaded");
    }
    mText.setFont(mFont);
    mText.setString("Score: ");
    mText.setCharacterSize(24);
    mText.setFillColor(sf::Color::White);
    mText.setStyle(sf::Text::Bold);
    mText.setFillColor(sf::Color::Black);

    if (!mHighScoreFont.loadFromFile("../textures/Fonts/Arial.ttf")) {
        throw std::runtime_error("Highscore font not loaded");
    }
    mHighScoreText.setFont(mHighScoreFont);
    mHighScoreText.setString("Highscore: ");
    mHighScoreText.setCharacterSize(24);
    mHighScoreText.setFillColor(sf::Color::White);
    mHighScoreText.setStyle(sf::Text::Bold);
    mHighScoreText.setPosition(0, 30);
    mHighScoreText.setFillColor(sf::Color::Black);

    mController->jumpPlayer();
    mController->jumpPlayer();
}

void Game::render() {
    // Clear the window
    mWindow->clear(sf::Color::White);

    // Draw the entities (player, platforms, BG_Tiles, bonuses)
    for (const std::shared_ptr<Game_Repr::Platform>& i: mPlatforms) {
        mWindow->draw(*i->getMPlatform());
        if (i->getBonus() != nullptr) {
            mWindow->draw(*i->getBonus()->getMBonusSprite());

            // For debugging purposes, draw debug hitbox of the bonus
//            mWindow->draw(*i->getBonus()->getMBonus());
        }

    }
    // For debugging, draw the debug hitbox of the player
    mWindow->draw(*mPlayer->getMHitboxDebug());
    mWindow->draw(*mPlayer->getMPlayer());
    mWindow->draw(mText);
    mWindow->draw(mHighScoreText);
    if (mController->checkEndGame()) {
        mWindow->draw(mGameOverText);
    }
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
    // Update jetpack with delta time
    mController->getWorld()->getMPlayer()->updateJetpack();
    if (mController->checkEndGame()) {
        mController->freezeWorld();
        if (!mGameOverFont.loadFromFile("../textures/Fonts/Arial.ttf")) {
            throw std::runtime_error("Game Over font not loaded");
        }
        mGameOverText.setFont(mGameOverFont);
        mGameOverText.setString("Game Over! Your score: " + std::to_string(Score::getInstance().getMScore()) + "\n Highscore: " + std::to_string(Score::getInstance().getHighScore()));
        mGameOverText.setCharacterSize(35);
        mGameOverText.setFillColor(sf::Color::White);
        mGameOverText.setStyle(sf::Text::Bold);
        mGameOverText.setOrigin(mGameOverText.getLocalBounds().width / 2, mGameOverText.getLocalBounds().height / 2);
        mGameOverText.setPosition((float)Config::windowWidth / 2, (float)Config::windowHeight / 2);
        mGameOverText.setFillColor(sf::Color::Black);
    }
    else {
        if (mKeyStates[sf::Keyboard::D] || mKeyStates[sf::Keyboard::Right]) {
            mController->movePlayerRight();
        }
        if (mKeyStates[sf::Keyboard::A] || mKeyStates[sf::Keyboard::Left]) {
            mController->movePlayerLeft();
        }

        // For debugging purposes, have a custom jump button
        /*if (mKeyStates[sf::Keyboard::Space] || mKeyStates[sf::Keyboard::Up]) {
            mController->jumpPlayer();
        }*/
        if (mKeyStates[sf::Keyboard::F]) {
            mController->freezeWorld();
        }
        mController->outOfBounds();
        if (mController->checkCollision()) {
            mController->jumpPlayer();
        }
        mController->checkPlayerBonusCollision();
        mController->updateWorld();
        mPlatforms.clear();
        for (const std::shared_ptr<Logic_Library::Platform>& i: mController->getWorld()->getMPlatforms()) {
            mPlatforms.push_back(i->getObserver());
        }
        mText.setString("Score: "+std::to_string(Score::getInstance().getMScore()));

        static bool checkpointReached = false;
        if (Score::getInstance().getMScore() > 0 and Score::getInstance().getMScore() % 20000 < 60 and !checkpointReached) {
            Config::amountOfPlatforms--;
            std::cout << "Checkpoint reached" << std::endl;
            checkpointReached = true;
        } else if (Score::getInstance().getMScore() % 20000 >= 60) {checkpointReached = false;}

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
    while (mWindow->isOpen()) {
        Stopwatch::getInstance().start();
        processEvents();
        update();
        render();
        Stopwatch::getInstance().stop();
        auto timeLeft = (1.f / 60.f) - Stopwatch::getInstance().getElapsedTime();
        sleep(timeLeft);
    }
}