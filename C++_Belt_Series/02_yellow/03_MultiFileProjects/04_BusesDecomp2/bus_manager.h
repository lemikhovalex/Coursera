//
// Created by lemikhovalex on 16.07.2020.
//
#include "string"
#include "map"
#include "vector"
#include "responses.h"
using namespace std;

class BusManager {
private:
    map<string, vector<string>> bus_stops;
    map<string, vector<string>> stop_buses;
public:
    void AddBus(const string& bus, const vector<string>& stops);

    BusesForStopResponse GetBusesForStop(const string& stop) const;

    StopsForBusResponse GetStopsForBus(const string& bus) const;

    AllBusesResponse GetAllBuses() const;
};