//
// Created by lemikhovalex on 16.07.2020.
//
#pragma once
#include "iostream"
#include "vector"
#include "map"
using namespace std;
struct BusesForStopResponse {
    // Наполните полями эту структуру
    vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
    // Наполните полями эту структуру
    map<string, vector<string>> stops_buses_int;
    vector<string> keys;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r);


struct AllBusesResponse {
    // Наполните полями эту структуру
    map<string, vector<string>> bus_stops;
};
ostream& operator << (ostream& os, const AllBusesResponse& r);