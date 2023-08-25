#pragma once
#include <chrono>

class Timer
{
public:
    Timer();
    void Reset();
    double Elapsed();
private:
    std::chrono::high_resolution_clock::time_point startTime;
};