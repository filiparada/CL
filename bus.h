#ifndef BUS_H
#define BUS_H

#include <vector>
#include "passenger.h"

class Bus {
public:
    Bus(int initialPosition);
    void move();
    void loadPassenger(Passenger passenger);
    void unloadPassengers(int currentStop);
    int getPosition() const;
    int getPassengers() const;
    bool isFull() const;

private:
    int position;
    std::vector<Passenger> passengers;
    static const int capacity = 40;
    static const int speed = 5;
};

#endif