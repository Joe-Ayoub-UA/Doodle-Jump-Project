//
// Created by Joe Ayoub on 14/11/24 at 15:20.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_RANDOM_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_RANDOM_H
#include "../../Config.h"
#include "../Coordinates/Coordinates.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>
#include <random>

/**
 * @brief class to generate random digits.
 */
class Random {
private:
    /// @brief x_range: pair of integers, which is the range of the x coordinate.
    std::pair<int, int> x_range;

    /// @brief y_range: pair of integers, which is the range of the y coordinate.
    std::pair<int, int> y_range;

    /// @brief mersenne: mt19937, which is the random number generator.
    std::mt19937 mersenne;

    /// @brief rd: random_device, which is the random device.
    std::random_device rd{};

public:
    /**
     * @brief Default constructor for the Random class
     */
    Random();

    /**
     * @brief Constructor for the Random class
     * @param xRange: pair of integers, which is the range of the x coordinate.
     * @param yRange: pair of integers, which is the range of the y coordinate.
     */
    Random(const std::pair<int, int>& xRange, const std::pair<int, int>& yRange);

    /**
     * @brief Destructor for the Random class
     */
    virtual ~Random();

    /**
     * @brief Function to get the instance of the Random class
     * @return the instance of the Random class
     */
    static Random& getInstance();

    /**
     * @brief Function to generate a random integer
     * @param min: int, which is the minimum value of the random integer.
     * @param max: int, which is the maximum value of the random integer.
     * @return the random integer
     */
    int randomInt(int min, int max);

    /**
     * @brief Function to generate a random float
     * @param min: float, which is the minimum value of the random float.
     * @param max: float, which is the maximum value of the random float.
     * @return the random float
     */
    float randomFloat(float min, float max);

    /**
     * @brief Function to generate a random boolean
     * @return the random boolean
     */
    bool randomBool();

    /**
     * @brief Function to generate a random coordinates
     * @return the random coordinates
     */
    Coordinates generateCoor();

    /**
     * @brief Function to get the range of the x coordinate
     * @return the range of the x coordinate
     */
    const std::pair<int, int>& getXRange() const;

    /**
     * @brief Function to set the range of the x coordinate
     * @param xRange: pair of integers, which is the new range of the x coordinate.
     */
    void setXRange(const std::pair<int, int>& xRange);

    /**
     * @brief Function to get the range of the y coordinate
     * @return the range of the y coordinate
     */
    const std::pair<int, int>& getYRange() const;

    /**
     * @brief Function to set the range of the y coordinate
     * @param yRange: pair of integers, which is the new range of the y coordinate.
     */
    void setYRange(const std::pair<int, int>& yRange);
};

#endif // INC_2024_PROJECT_JOE_AYOUB_UA_RANDOM_H
