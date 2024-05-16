#include "bus.h"

Bus::Bus(int initialPosition) : position(initialPosition) {}

void Bus::move() {
    position += speed;
    if (position >= 10000) {
        position -= 10000;
    }
}

void Bus::loadPassenger(Passenger passenger) {
    passengers.push_back(passenger);
}

void Bus::unloadPassengers(int currentStop) {
    std::vector<Passenger> remainingPassengers;
    for (const auto &passenger : passengers) {
        if (passenger.getDestination() != currentStop) {
            remainingPassengers.push_back(passenger);
        }
    }
    passengers = remainingPassengers;
}
//void Bus::unloadPassengers(int currentStop) {
//    passengers.erase(std::remove_if(passengers.begin(), passengers.end(),
//                                    [currentStop](Passenger p) { return p.getDestination() == currentStop; }),
//                     passengers.end());
//}

int Bus::getPosition() const {
    return position;
}

int Bus::getPassengers() const {
    return passengers.size();
}

bool Bus::isFull() const {
    return passengers.size() == capacity;
}