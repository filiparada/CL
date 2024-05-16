#include <cstdlib>
#include "stop.h"

Stop::Stop(int position) : position(position) {}

void Stop::generatePassengers() {
    if (rand() % 3600 < 10) {
        int destination = rand() % 25;
        if (destination >= position) {
            ++destination;
        }
        addPassenger(Passenger(destination));
    }
}

void Stop::addPassenger(Passenger passenger) {
    waitingPassengers.push(passenger);
}

Passenger Stop::removePassenger() {
    Passenger passenger = waitingPassengers.front();
    waitingPassengers.pop();
    return passenger;
}

int Stop::getWaitingPassengers() const {
    return waitingPassengers.size();
}

bool Stop::hasWaitingPassengers() const {
    return !waitingPassengers.empty();
}