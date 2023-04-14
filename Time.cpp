//
// Created by radziu2402 on 10.03.2023.
//

#include "Time.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

// Funkcja timeStart() - ustawia wartość zmiennej initialTime na aktualny czas.
void Time::timeStart() {
    initialTime = high_resolution_clock::now();
}

// Funkcja timeStop() - ustawia wartość zmiennej endTime na aktualny czas.
void Time::timeStop() {
    endTime = high_resolution_clock::now();
}

// Funkcja elapsedTime() - zwraca czas w nanosekundach między initialTime a endTime.
long Time::elapsedTime() {
    return duration_cast<nanoseconds>(endTime - initialTime).count();
}