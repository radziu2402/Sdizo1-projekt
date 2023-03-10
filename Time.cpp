//
// Created by radziu2402 on 10.03.2023.
//

#include "Time.h"
#include <chrono>
using namespace std;
using namespace std::chrono;


void Time::timeStart() {
    initialTime = high_resolution_clock::now();
}

void Time::timeStop() {
    endTime = high_resolution_clock::now();
}

long Time::elapsedTime() {
    return duration_cast<milliseconds> (initialTime - endTime).count();
}
