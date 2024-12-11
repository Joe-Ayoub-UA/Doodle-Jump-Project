//
// Created by Joe Ayoub on 14/11/24 at 15:20.
//

#include "Random.h"

Random::Random(int sizeXX, int sizeYY) : sizeX(sizeXX), sizeY(sizeYY), prevX(-1), prevY(-1) {
    static bool isSeeded = false;
    if (!isSeeded) {
        srand(static_cast<unsigned int>(time(nullptr)));
        isSeeded = true;
    }
}

Random::~Random() {
}

std::pair<int, int> Random::generateCoor() {
    std::pair<int, int> coordinates{};
    if (prevX == -1) {
        coordinates.first = (rand() % sizeX);
    }
    else {
        int minX = std::max(0, prevX - (sizeX/2));
        int maxX = std::min(sizeX -1, prevX + (sizeX/2));
        coordinates.first = minX + (rand() % (maxX - minX + 1));
    }
    if (prevY == -1) {
        coordinates.second = (rand() % sizeY);
    }
    else {
        int minY = std::max(0, prevY - (sizeY/2));
        int maxY = std::min(sizeY - 1, prevY + (sizeY/2));
        coordinates.second = minY + (rand() % (maxY - minY + 1));
    }
    return coordinates;
}

int Random::getSizeX() const {
    return sizeX;
}

void Random::setSizeX(int sizeX) {
    Random::sizeX = sizeX;
}

int Random::getSizeY() const {
    return sizeY;
}

void Random::setSizeY(int sizeY) {
    Random::sizeY = sizeY;
}

int mains() {
    std::shared_ptr<Random> random = std::make_shared<Random>(100,30);

    for (int i=0;i<10;i++) {
        std::cout << 1 + random->generateCoor().first << ", " << 1 + random->generateCoor().second << std::endl;
    }
    return 0;
}
