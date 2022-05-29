#ifndef TIMER
#define TIMER

#include <chrono>

class Timer
    {
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> startTimePoint;

    public:
        Timer()
            : startTimePoint(std::chrono::high_resolution_clock::now()) { }

        ~Timer()
        {
            stop();
        }

    public:
        /**
         * Stops the timer and invokes the callback function.
         */
        long double stop()
        {
            auto endTimePoint = std::chrono::high_resolution_clock::now();

            auto start = std::chrono::time_point_cast<std::chrono::milliseconds>(this->startTimePoint).time_since_epoch().count();
            auto end = std::chrono::time_point_cast<std::chrono::milliseconds>(endTimePoint).time_since_epoch().count();

            return (long double)(end - start);
        }
    };

#endif