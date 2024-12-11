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

class Stopwatch {
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;

public:
    Stopwatch();

    // Restarts the stopwatch and returns the elapsed time in seconds
    float restart();

    // Returns the elapsed time in seconds without restarting
    float getElapsedTime() const;
};


#endif //INC_2024_PROJECT_JOE_AYOUB_UA_STOPWATCH_H
