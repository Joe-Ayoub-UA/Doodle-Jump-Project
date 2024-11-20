//
// Created by Joe Ayoub on 14/11/24 at 15:49.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_GAME_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_GAME_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../../Controller/Controller.h"
#include <memory>
using namespace std;

class Game {
private:
    shared_ptr<Controller> controller = std::make_shared<Controller>();

    unique_ptr<sf::RenderWindow> mWindow{};

    shared_ptr<sf::CircleShape> mPlayer{};
//    sf::CircleShape mPlayer;

    void processEvents();

    void update(sf::Time deltatime);

    void render();
public:
    Game();

    void initgame();

    void run();
};


#endif //INC_2024_PROJECT_JOE_AYOUB_UA_GAME_H
