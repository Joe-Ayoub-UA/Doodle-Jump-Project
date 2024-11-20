//
// Created by Joe Ayoub on 14/11/24 at 15:21.
//

#include "Stopwatch.h"

Stopwatch::Stopwatch() {}

Stopwatch::~Stopwatch() {

}

void Stopwatch::startStopwatch() {
    beginning = std::chrono::high_resolution_clock::now();
}

void Stopwatch::stopStopwatch() {
    std::chrono::time_point now = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float,std::milli>  duration = now - beginning;
    delta = duration.count();
}

float Stopwatch::getDelta() const {
    return delta;
}
