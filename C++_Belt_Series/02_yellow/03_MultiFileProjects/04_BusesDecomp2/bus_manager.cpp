//
// Created by lemikhovalex on 16.07.2020.
//
#include "bus_manager.h"
void BusManager::AddBus(const string& bus, const vector<string>& stops) {
    // Реализуйте этот метод
    bus_stops[bus] = stops;
    for(string stop : stops){
        stop_buses[stop].push_back(bus);
    }
}

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
    // Реализуйте этот метод
    StopsForBusResponse out;
    if (bus_stops.count(bus) == 0){
        return out;
    }else{
        out.keys = bus_stops.at(bus);
        for(auto stop_for_bus : bus_stops.at(bus)){
            out.stops_buses_int[stop_for_bus] = {};
            for (auto bus_for_stop : stop_buses.at(stop_for_bus)){
                if (bus_for_stop != bus){
                    out.stops_buses_int[stop_for_bus].push_back(bus_for_stop);
                }
            }
        }
    }
    return out;
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
    BusesForStopResponse out;
    if (stop_buses.count(stop) == 1) {
        out = {stop_buses.at(stop)};
    }
    return out;
}

AllBusesResponse BusManager::GetAllBuses() const {
    // Реализуйте этот метод
    AllBusesResponse out = {bus_stops};
    return out;
}
