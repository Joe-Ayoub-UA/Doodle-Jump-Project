//
// Created by Joe Ayoub on 14/11/24 at 15:49.
//

#include "Game.h"

Game::Game() : mWindow(new sf::RenderWindow(sf::VideoMode(600, 800), "Doodle Jump")), mPlayer()
{
    mWindow = std::make_unique<sf::RenderWindow>(sf::VideoMode(600, 800),"Doodle Jump");
    mPlayer = std::make_shared<sf::CircleShape>(40.f);
    //mPlayer->setRadius(40.f);
    mPlayer->setPosition(100.f, 100.f);
    //mPlayer->setOrigin(120.f,100.f);
    mPlayer->setFillColor(sf::Color::Yellow);

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
//        sf::Event event;
//        while (mWindow->pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
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
    sf::Event event;
    while (mWindow->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::KeyPressed:
                controller->handleInputs(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                controller->handleInputs(event.key.code,false);
                break;
            case sf::Event::Closed:
                mWindow->close();
                break;
        }
    }
}

void Game::update(sf::Time deltatime) {
    sf::Vector2f movement(0.f, 0.f);
    if (controller->left) {
        movement.x -= 400.f;
    }
    if (controller->right) {
        movement.x += 400.f;
    }
    cout << mPlayer->getPosition().x << endl;
    if (mPlayer->getPosition().x < mPlayer->getRadius()*(-2)) {
        mPlayer->setPosition((float)mWindow->getSize().x+mPlayer->getRadius(),mPlayer->getPosition().y);
    }
    if (mPlayer->getPosition().x > (float)mWindow->getSize().x+mPlayer->getRadius()) {
        mPlayer->setPosition(-mPlayer->getRadius(),mPlayer->getPosition().y);
    }
    mPlayer->move(movement * deltatime.asSeconds());
}

void Game::render() {
    mWindow->clear();
    mWindow->draw(*mPlayer);
    mWindow->display();
}

void Game::run() {
    sf::Clock clock;
    while (mWindow->isOpen()) {
        sf::Time deltatime = clock.restart();
        processEvents();
        update(deltatime);
        render();
    }
}
