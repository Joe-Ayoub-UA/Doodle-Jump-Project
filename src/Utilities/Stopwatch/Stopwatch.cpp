////
//// Created by Joe Ayoub on 14/11/24 at 15:21.
////
//
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

Stopwatch::~Stopwatch() = default;

