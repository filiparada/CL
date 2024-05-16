#ifndef PASSENGER_H
#define PASSENGER_H

class Passenger {
public:
    Passenger(int destination);
    int getDestination() const;

private:
    int destination;
};

#endif



