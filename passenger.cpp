#include "passenger.h"

Passenger::Passenger(int destination) : destination(destination) {}

int Passenger::getDestination() const {
    return destination;
}