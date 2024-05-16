#include <iostream>
#include <iomanip>
#include <cmath>
#include "bus.h"
#include "stop.h"
using namespace std;
const int simulationTime = 43200;
const int numberOfStops = 25;
const int numberOfBuses = 4;

int main() {
    vector<Stop> stops;
    for (int i = 0; i < numberOfStops; ++i) {
        stops.emplace_back(i * 400);
    }

    vector<Bus> buses;
    for (int i = 0; i < numberOfBuses; ++i) {
        buses.emplace_back(i * 2500);
    }

    for (int t = 1; t <= simulationTime; ++t) {
        for (auto &stop : stops) {
            stop.generatePassengers();
        }

        for (auto &bus : buses) {
            int currentStop = bus.getPosition() / 400;

            if (bus.getPosition() % 400 == 0) {
                bus.unloadPassengers(currentStop);
                for (int i = 0; i < 5 && stops[currentStop].hasWaitingPassengers() && !bus.isFull(); ++i) {
                    bus.loadPassenger(stops[currentStop].removePassenger());
                }
            }

            bus.move();

            if (bus.getPosition() % 400 == 0) {
                for (int i = 0; i < 5; ++i) {
                    bus.move();
                }
            }
        }

        if (t % 3600 == 0) {
            cout << "t=" << t << "s\n";
            cout << "=======\n";
            for (int i = 0; i < numberOfStops; ++i) {
                cout << "parada " << i + 1 << " " << stops[i].getWaitingPassengers() << " pax esperando\n";
            }
            for (int i = 0; i < numberOfBuses; ++i) {
                cout << "bus " << i + 1 << " " << buses[i].getPassengers() << " pax, en y=" << buses[i].getPosition() << "\n";
            }

            double S = 0, Q = 0;
            for (int i = 0; i < numberOfBuses; ++i) {
                int j = (i + 1) % numberOfBuses;
                int d = buses[j].getPosition() - buses[i].getPosition();
                if (d < 0) {
                    d += 10000;
                }
                S += d;
                Q += d * d;
            }
            S /= numberOfBuses;
            Q /= numberOfBuses;
            double C = sqrt(Q - S * S) / S;

            cout << fixed;
            cout << "coeficiente de bunching: " << setprecision(5) << C << "\n";
        }
    }
}