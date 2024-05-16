#ifndef STOP_H
#define STOP_H

#include <queue>
#include "passenger.h"

class Stop {
public:
    Stop(int position);
    void generatePassengers();
    void addPassenger(Passenger passenger);
    Passenger removePassenger();
    int getWaitingPassengers() const;
    bool hasWaitingPassengers() const;

private:
    int position;
    std::queue<Passenger> waitingPassengers;
};

#endif



