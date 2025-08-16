//
// Created by Joe Ayoub on 14/11/24 at 15:20.
//

#include "Random.h"

//Random::Random(int sizeXX, int sizeYY) : sizeX(sizeXX), sizeY(sizeYY), prevX(-1), prevY(-1) {
//    static bool isSeeded = false;
//    if (!isSeeded) {
//        srand(static_cast<unsigned int>(time(nullptr)));
//        isSeeded = true;
//    }
//}

Random::Random(){
    this->setXRange(std::make_pair(0, Config::windowWidth));
    this->setYRange(std::make_pair(0, Config::windowHeight));
    static bool isSeeded = false;
    if (!isSeeded) {
        srand(static_cast<unsigned int>(time(nullptr)));
        isSeeded = true;
    }
    mersenne = std::mt19937(rd());
}

Random::~Random() {
}

Random &Random::getInstance() {
    static Random instance;
    return instance;
}

/**
 * @brief Generates a random integer between min and max.
 * @param min
 * @param max
 * @return int, which is a random number between min and max.
 */
int Random::randomInt(int min, int max) {
    if (min == max) {
        return min;
    }
    if ( min > max ) {
        std::swap(min, max);
    }
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(mersenne);
}

/**
 * @brief Generates a random float between min and max.
 * @param min
 * @param max
 * @return float, which is a random number between min and max.
 */
float Random::randomFloat(float min, float max) {
    if (min == max) {
        return min;
    }
    if ( min > max ) {
        std::swap(min, max);
    }
    std::uniform_real_distribution<float> distribution(min, max);
    return distribution(mersenne);
}

/**
 * @brief Generates a random boolean.
 * @return bool, which is a random boolean.
 */
 bool Random::randomBool() {
     return randomInt(0, 1) == 1;
 }

Coordinates Random::generateCoor() {
    Coordinates coordinates{};
//    if (prevX == -1) {
//        coordinates.setX(rand() % x_range.second);
//    }
//    else {
//        int minX = std::max(0, prevX - (x_range.second/2));
//        int maxX = std::min(x_range.second -1, prevX + (x_range.second/2));
//        coordinates.setX(minX + (rand() % (maxX - minX + 1)));
//    }
//    if (prevY == -1) {
//        coordinates.setY(rand() % y_range.second);
//    }
//    else {
//        int minY = std::max(0, prevY - (y_range.second/2));
//        int maxY = std::min(y_range.second - 1, prevY + (y_range.second/2));
//        coordinates.setY(minY + (rand() % (maxY - minY + 1)));
//    }
    coordinates.setX(randomFloat((float)x_range.first, (float)x_range.second));
    coordinates.setY(randomFloat((float)y_range.first, (float)y_range.second));
    return coordinates;
}

const std::pair<int, int> &Random::getXRange() const {
    return x_range;
}

void Random::setXRange(const std::pair<int, int> &xRange) {
    x_range = xRange;
}

const std::pair<int, int> &Random::getYRange() const {
    return y_range;
}

void Random::setYRange(const std::pair<int, int> &yRange) {
    y_range = yRange;
}

Random::Random(const std::pair<int, int> &xRange, const std::pair<int, int> &yRange) : x_range(xRange),
                                                                                       y_range(yRange) {}

