//
// Created by lemikhovalex on 16.07.2020.
//
#include "responses.h"

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
    // Реализуйте эту функцию
    if (r.buses.size() == 0){
        os << "No stop";
    }else{
        for(string bus : r.buses){
            os << bus << " ";
        }
    }
    return os;
}

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
    // Реализуйте эту функцию
    bool first = true;
    if (r.keys.size() == 0){
        os << "No bus";
    }else{
        for(auto key : r.keys){
            if(first == true){
                first = false;
            } else{
                os << endl;
            }
            os << "Stop " << key << ": ";
            if (r.stops_buses_int.at(key).size() < 1) {
                os << "no interchange";
            }else{
                for (auto bus_for_stop : r.stops_buses_int.at(key)){
                    os << bus_for_stop << " ";
                }
            }
        }
    }
    return os;
}

ostream& operator << (ostream& os, const AllBusesResponse& r) {
    // Реализуйте эту функцию
    if (r.bus_stops.empty()){
        os << "No buses";
    }else{
        bool first = true;
        for (auto bus : r.bus_stops){
            if (first){
                first = false;
            } else{
                os << endl;
            }
            os << "Bus " << bus.first << ": ";
            for (auto stop : bus.second){
                os << stop << " ";
            }
        }
    }
    return os;
}

