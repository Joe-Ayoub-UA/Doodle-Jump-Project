//
// Created by Joe Ayoub on 14/11/24 at 15:21.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_STOPWATCH_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_STOPWATCH_H
#include <chrono>

//class Stopwatch {
//private:
//    float delta;
//
//    std::chrono::time_point<std::chrono::high_resolution_clock> beginning{};
//
//public:
//    Stopwatch();
//
//    virtual ~Stopwatch();
//
//    void startStopwatch();
//
//    void stopStopwatch();
//
//    void continueStopwatch();
//
//    float getDelta() const;
//
//    void setBeginning(const std::chrono::time_point<std::chrono::high_resolution_clock> &newBeginning);
//
//    const std::chrono::time_point<std::chrono::high_resolution_clock> &getBeginning() const;
//
//};
/**
 * @brief Stopwatch class
 */
class Stopwatch {
private:
    /// Time point when the stopwatch was started
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;

    /// Time point when the stopwatch was stopped
    std::chrono::time_point<std::chrono::high_resolution_clock> stopTime;

public:
    /***
     * @brief Default constructor for Stopwatch class
     */
    Stopwatch();

    /**
     * @brief Instance of the Stopwatch class
     */
     static Stopwatch& getInstance();

    /**
    * @brief Starts the stopwatch
    */
    void start();

    /**
     * @brief Stops the stopwatch and returns the elapsed time in seconds
     * @return Elapsed time in seconds
     */
    void stop();

    /***
     * @brief Destructor for Stopwatch class
     */
    virtual ~Stopwatch();

    // Restarts the stopwatch and returns the elapsed time in seconds
    float restart();

    // Returns the elapsed time in seconds without restarting
    float getElapsedTime() const;
};


#endif //INC_2024_PROJECT_JOE_AYOUB_UA_STOPWATCH_H
