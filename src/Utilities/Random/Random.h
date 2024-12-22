//
// Created by Joe Ayoub on 14/11/24 at 15:20.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_RANDOM_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_RANDOM_H
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <memory>
#include "../Coordinates/Coordinates.h"
#include <random>


/**
 * @brief class to generate random digits.
 */
class Random {
private:
    std::pair<int,int> x_range;
    std::pair<int,int> y_range;
    int prevX;
    int prevY;
    std::mt19937 mersenne;
    std::random_device rd{};
public:
    Random();

    Random(const std::pair<int, int> &xRange, const std::pair<int, int> &yRange);

    virtual ~Random();

    static Random& getInstance();

    int randomInt(int min,int max);

    float randomFloat(float min, float max);

    Coordinates generateCoor() const;

    const std::pair<int, int> &getXRange() const;

    void setXRange(const std::pair<int, int> &xRange);

    const std::pair<int, int> &getYRange() const;

    void setYRange(const std::pair<int, int> &yRange);

};


#endif //INC_2024_PROJECT_JOE_AYOUB_UA_RANDOM_H
