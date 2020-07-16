//
// Created by lemikhovalex on 16.07.2020.
//
#include <iostream>
#pragma once
#include "vector"
#include "string"
using namespace std;

enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

istream& operator >> (istream& is, Query& q);
