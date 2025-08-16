//
// Created by Joe Ayoub on 5/11/24.
//
#include <iostream>
#include <SFML/Graphics.hpp>

//#include "Game Representation/_Game/Game.h"
#include "Game Representation/_Game//Game.h"



int main()
{
    Game game{};
    try {
        game.run();
    }
    catch (const std::exception &e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    catch (...) {
        std::cerr << "An unknown error occurred." << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}