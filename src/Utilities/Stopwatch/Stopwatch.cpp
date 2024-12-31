////
//// Created by Joe Ayoub on 14/11/24 at 15:21.
////
//
//#include "Stopwatch.h"
//
//Stopwatch::Stopwatch() : delta(0), beginning(std::chrono::high_resolution_clock::now()){}
//
//Stopwatch::~Stopwatch() = default;
//
//void Stopwatch::startStopwatch() {
//    beginning = std::chrono::high_resolution_clock::now();
//}
//
//void Stopwatch::stopStopwatch() {
//    std::chrono::time_point now = std::chrono::high_resolution_clock::now();
//    std::chrono::duration<float>  duration = now - beginning;
//    delta = duration.count();
//}
//
//void Stopwatch::continueStopwatch() {
//
//}
//
//float Stopwatch::getDelta() const {
//    return delta;
//}
//
//void Stopwatch::setBeginning(const std::chrono::time_point<std::chrono::high_resolution_clock> &newBeginning) {
//    Stopwatch::beginning = newBeginning;
//}
//
//const std::chrono::time_point<std::chrono::high_resolution_clock> &Stopwatch::getBeginning() const {
//    return beginning;
//}


#include "Stopwatch.h"

Stopwatch::Stopwatch() {
    startTime = std::chrono::high_resolution_clock::now();
}

Stopwatch& Stopwatch::getInstance() {
    static Stopwatch instance;
    return instance;
}

void Stopwatch::start() {
    startTime = std::chrono::high_resolution_clock::now();
}

void Stopwatch::stop() {
    stopTime = std::chrono::high_resolution_clock::now();
}

float Stopwatch::getElapsedTime() const {
    auto now = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration<float>((stopTime > startTime ? stopTime : now) - startTime).count();
    return elapsed;
}



float Stopwatch::restart() {
    auto now = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration<float>(now - startTime).count();
    startTime = now; // Reset the start time
    return elapsed;
}

//float Stopwatch::getElapsedTime() const {
//    auto now = std::chrono::high_resolution_clock::now();
//    return std::chrono::duration<float>(now - startTime).count();
//}

Stopwatch::~Stopwatch() = default;

