#include <iostream>
#include "vector"
#include "map"

using namespace std;

void new_bus(map<string, vector<string>>& bus_stops, map<string, vector<string>>& stop_buses,
        string bus, vector<string> stops){
    bus_stops[bus] = stops;
    for(string stop : stops){
        stop_buses[stop].push_back(bus);
    }
}

void buses_for_stop(map<string, vector<string>> stop_buses, string stop){
    if (stop_buses.count(stop) == 0){
        cout << "No stop";
    }else{
        for(string bus : stop_buses[stop]){
            cout << bus << " ";
        }
    }
    cout << endl;
}

void stops_for_bus(map<string, vector<string>> bus_stops, map<string, vector<string>> stop_buses, string bus){
    if (bus_stops.count(bus) == 0){
        cout << "No bus" << endl;
    }else{
        for(auto stop_for_bus : bus_stops[bus]){
            cout << "Stop " << stop_for_bus << ": ";
            if (stop_buses[stop_for_bus].size() <= 1) {
                cout << "no interchange" << endl;
            }else{
                for (auto bus_for_stop : stop_buses[stop_for_bus]){
                    if (bus_for_stop != bus){
                        cout << bus_for_stop << " ";
                    }
                }
                cout << endl;
            }
        }
    }
}

void all_buses(const map<string, vector<string>>& bus_stops){
    if (bus_stops.empty()){
        cout << "No buses" << endl;
    }else{
        for (auto bus : bus_stops){
            cout << "Bus " << bus.first << ": ";
            for (auto stop : bus.second){
                cout << stop << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    int n;
    cin >> n;
    string command;
    int inps_count;
    string inp_str1, inp_str2;
    vector<string> inps;
    map<string, vector<string>> bus_stops;
    map<string, vector<string>> stop_buses;
    for (int i = 0; i < n; i ++){
        cin >> command;
        if (command == "NEW_BUS"){
            cin >> inp_str1 >> inps_count;
            inps = {};
            for (int j = 0; j < inps_count; j ++){
                cin >> inp_str2;
                inps.push_back(inp_str2);
            }
            new_bus(bus_stops, stop_buses, inp_str1, inps);
        }
        if (command == "BUSES_FOR_STOP"){
            cin >> inp_str1;
            buses_for_stop(stop_buses, inp_str1);
        }
        if (command == "STOPS_FOR_BUS"){
            cin >> inp_str1;
            stops_for_bus(bus_stops, stop_buses, inp_str1);
        }
        if (command == "ALL_BUSES"){
            all_buses(bus_stops);
        }
    }
    return 0;
}
