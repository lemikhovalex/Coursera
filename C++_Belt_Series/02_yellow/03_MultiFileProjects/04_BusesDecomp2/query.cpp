//
// Created by lemikhovalex on 16.07.2020.
//

//
// Created by lemikhovalex on 16.07.2020.
//
#include "query.h"

istream& operator >> (istream& is, Query& q) {
    // Реализуйте эту функцию
    q = Query();
    string command;
    int inp_count = 0;
    string inp_str1, inp_str2;
    vector<string> inps;
    is >> command;
    if (command == "NEW_BUS"){
        q.type = QueryType::NewBus;
        is >> q.bus >> inp_count;
        inps = {};
        for (int j = 0; j < inp_count; j ++){
            is >> inp_str2;
            q.stops.push_back(inp_str2);
        }
    }
    if (command == "BUSES_FOR_STOP"){
        q.type = QueryType::BusesForStop;
        is >> q.stop;
    }
    if (command == "STOPS_FOR_BUS"){
        q.type = QueryType::StopsForBus;
        is >> q.bus;
    }
    if (command == "ALL_BUSES"){
        q.type = QueryType::AllBuses;
    }
    return is;
}
