#include "Timer.h"

Timer::Timer() {
    startTime = std::chrono::high_resolution_clock::now();
}

void Timer::Reset() {
    startTime = std::chrono::high_resolution_clock::now();
}

double Timer::Elapsed() {
    auto currentTime = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime).count() / 1000.0;
}