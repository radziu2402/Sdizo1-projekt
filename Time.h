//
// Created by radziu2402 on 10.03.2023.
//

#ifndef SDIZO1_TIME_H
#define SDIZO1_TIME_H

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Time {
public:
    high_resolution_clock::time_point initialTime;
    high_resolution_clock::time_point endTime;

    void timeStart();

    void timeStop();

    long elapsedTime();
};


#endif //SDIZO1_TIME_H
