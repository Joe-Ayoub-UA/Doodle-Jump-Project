//
// Created by Joe Ayoub on 14/11/24 at 15:49.
//

#include "Game.h"
#include <unistd.h>
#include <thread>

Game::Game() : mWindow(std::make_unique<sf::RenderWindow>(sf::VideoMode(Config::windowWidth, Config::windowHeight), "Doodle Jump"))
{
    //mWindow = std::make_unique<sf::RenderWindow>(sf::VideoMode(600, 800),"Doodle Jump");

//    sf::Texture texture;
//    if (!texture.loadFromFile("/home/s0230501/CLionProjects/AP_Project_DoodleJump/2024-project-Joe-Ayoub-UA/textures/Doodle/NinjaDoodle.png")) {}
    //mPlayer = std::make_shared<sf::CircleShape>(40.f);
    //mPlayer->setRadius(40.f);
    mPlayer->getMPlayer()->setOrigin(mPlayer->getMPlayer()->getRadius(),mPlayer->getMPlayer()->getRadius());
    //mPlayer->setPosition(100.f, 100.f);
    float posX = static_cast<float>((float)mWindow->getSize().x / 2);
    float posY = static_cast<float>((float)mWindow->getSize().y / 2);
    mPlayer->getMPlayer()->setPosition(posX, posY);
    //mPlayer->setFillColor(sf::Color::Yellow);

    mStopwatch = std::make_shared<Stopwatch>();

    //initgame();
}

void Game::initgame() {
//    sf::CircleShape shape1;
//    shape1.setRadius(200);
//    shape1.setFillColor(sf::Color::Blue);
    // Declare and load a texture
//    sf::Texture texture;
//    texture.loadFromFile("../textures/Tile/TileReal.jpg");
//    sf::Sprite sprite;
//    sprite.setTexture(texture);
//    sprite.setTextureRect(sf::IntRect(100, 100, 600, 800));
//    sprite.setColor(sf::Color(255, 255, 255, 200));
//    sprite.setPosition(0, 0);
// Create a sprite
// Draw it
//    while (mWindow->isOpen()) {
////        if (x >= mWindow->getSize().x) {
////            y++;
////            x=0;
////        }
////        else if (y >= mWindow->getSize().y) {
////            y = 0;
////            x++;
////        }
////        else {
////            x++;
////        }
//        sf::Event mEvent;
//        while (mWindow->pollEvent(mEvent)) {
//            if (mEvent.type == sf::Event::Closed)
//                mWindow->close();
//        }
//        mWindow->clear();
//        mWindow->draw(sprite);
//        //mWindow.draw(shape1);
//        mWindow->display();
//        controller->handleInputs();
//    }
}

void Game::processEvents() {
    while (mWindow->pollEvent(mEvent)) {
        switch (mEvent.type) {
            case sf::Event::KeyPressed:
                controller->handleInputs(mEvent.key.code, true);
                break;
            case sf::Event::KeyReleased:
                controller->handleInputs(mEvent.key.code, false);
                break;
            case sf::Event::Closed:
                mWindow->close();
                break;
        }
    }
}

//void _Game::applyGravity() {
//    // Apply gravity
//    mPlayer->verticalSpeed += gravity;
//    movement.y += mPlayer->verticalSpeed;
//}
//
//void handleJump() {
//    // Handle jumping
//    if (controller->jump && mPlayer->getMPlayer()->getPosition().y >= mWindow->getSize().y - mPlayer->getMPlayer()->getRadius()) {
//        mPlayer->verticalSpeed = -350.f; // Adjust this value for jump strength
//    }
//}

void Game::update(sf::Time delta) {
    sf::Vector2f movement(0.f, 0.f);
    if (controller->left) {
        movement.x -= 350.f;
    }
    if (controller->right) {
        movement.x += 350.f;
    }

    // Apply gravity
    //TODO: Fix gravity to work properly, it has to speed up the player when falling down
//    mPlayer->verticalSpeed += gravity;
    movement.y += Config::gravity;

    // Handle jumping
    //TODO: Fix jumping, it is not even working. But this is because I still have to save the vertical speed of the player
    if (controller->jump && mPlayer->getMPlayer()->getPosition().y >= mWindow->getSize().y - mPlayer->getMPlayer()->getRadius()) {
//        mPlayer->verticalSpeed = -350.f; // Adjust this value for jump strength
        movement.y = -350.f; // Adjust this value for jump strength
    }

    // Check for ground collision
    if (mPlayer->getMPlayer()->getPosition().y >= mWindow->getSize().y - mPlayer->getMPlayer()->getRadius()) {
        mPlayer->getMPlayer()->setPosition(mPlayer->getMPlayer()->getPosition().x, mWindow->getSize().y - mPlayer->getMPlayer()->getRadius());
        movement.y = 0.f;
    }

    // Wrap around horizontally
    if (mPlayer->getMPlayer()->getPosition().x < mPlayer->getMPlayer()->getRadius() * (-2)) {
        mPlayer->getMPlayer()->setPosition((float)mWindow->getSize().x + mPlayer->getMPlayer()->getRadius(), mPlayer->getMPlayer()->getPosition().y);
    }
    if (mPlayer->getMPlayer()->getPosition().x > (float)mWindow->getSize().x + mPlayer->getMPlayer()->getRadius()) {
        mPlayer->getMPlayer()->setPosition(mPlayer->getMPlayer()->getRadius() * (-2), mPlayer->getMPlayer()->getPosition().y);
    }
    std::cout << movement.y << std::endl;
    mPlayer->getMPlayer()->move(movement * delta.asSeconds());
}

//void _Game::update(sf::Time delta) {
//    sf::Vector2f movement(0.f, 0.f);
//    if (controller->left) {
//        movement.x -= 350.f;
//    }
//    if (controller->right) {
//        movement.x += 350.f;
//    }
//    //cout << mPlayer->getPosition().x << endl;
//    if (mPlayer->getMPlayer()->getPosition().x < mPlayer->getMPlayer()->getRadius()*(-2)) {
//        mPlayer->getMPlayer()->setPosition((float)mWindow->getSize().x+mPlayer->getMPlayer()->getRadius(),mPlayer->getMPlayer()->getPosition().y);
//    }
//    if (mPlayer->getMPlayer()->getPosition().x > (float)mWindow->getSize().x+mPlayer->getMPlayer()->getRadius()) {
//        mPlayer->getMPlayer()->setPosition(mPlayer->getMPlayer()->getRadius()*(-2),mPlayer->getMPlayer()->getPosition().y);
//    }
////    if (mPlayer->getPosition().x < 0) {
////        mPlayer->setPosition((float)mWindow->getSize().x-1,mPlayer->getPosition().y);
////    }
////    if (mPlayer->getPosition().x > (float)mWindow->getSize().x) {
////        mPlayer->setPosition(1,mPlayer->getPosition().y);
////    }
//    mPlayer->getMPlayer()->move(movement * delta.asSeconds());
//}
/**
 * @brief This funcition makes sure the window keeps updating to the new position of the entities
 */
void Game::render() {
    mWindow->clear();
    mWindow->draw(*mPlayer->getMPlayer());
    mWindow->display();
}


/**
 * @brief This function runs the game and makes sure the needed events are processed, also stops the game when the window is closed or the program is stopped.
 * @attention Need to fix the stopwatch, make maybe use of the sleep(int) method to make sure it consistently updates.
 * @todo Stopwatch to work the same way as the sf::Clock and sf::Time: da kan ik doen door gebruik van sleep en dan
 *       update het ÉÉN keer per 1/60 second, dus gwn alles uitvoeren en dan wachten tot dat het genoeg is voor 1/60 seconde
 */

/*
 *     Stopwatch stopwatch;

    // Simulate a workload
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    float delta = stopwatch.restart(); // Get elapsed time and restart the stopwatch
    std::cout << "Elapsed time: " << delta << " seconds\n";

    // Simulate another workload
    std::this_thread::sleep_for(std::chrono::milliseconds(200));

    delta = stopwatch.restart(); // Get the new elapsed time
    std::cout << "Elapsed time: " << delta << " seconds\n";

 */
void Game::run() {
//    mStopwatch->startStopwatch;
    sf::Clock clock;
    while (mWindow->isOpen()) {

        sf::Time deltatime = clock.restart();
        processEvents();
        update(deltatime);
        render();

        //mStopwatch->stopStopwatch();
//        float elapsedTime = mStopwatch->getElapsedTime();
////        cout << "mStopwatch 1: " << elapsedTime << endl;
//        //cout << "deltatime: " << deltatime.asMilliseconds() << endl;
////        cout << "1/60 = " << 1.f/60.f << endl;
//
//        if (mStopwatch->getElapsedTime() < 1.f/60.f) {
//            auto now = std::chrono::high_resolution_clock::now();
//            auto sleepUntil = now + std::chrono::duration<float>(1.f / 60.f - elapsedTime);
//
//            std::this_thread::sleep_until(sleepUntil);
//        }
//        if (mStopwatch->getElapsedTime() >= 1.f/60.f) {
//            float deltaTime = mStopwatch->getElapsedTime(); // Time since last frame
////            mStopwatch->startStopwatch();
//            update(deltaTime);
////            deltatime = clock.restart();
//            render();
//        }
//        mStopwatch->continueStopwatch();
//        mStopwatch->setBeginning(
//                mStopwatch->getBeginning() + std::chrono::duration_cast<std::chrono::high_resolution_clock::duration>(
//                        std::chrono::duration<float>(mStopwatch->getDelta())
//                )
//        );
//        cout << "mStopwatch 2: " << mStopwatch->getDelta() << endl;

    }
}
