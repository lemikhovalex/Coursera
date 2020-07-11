#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

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

struct BusesForStopResponse {
  // Наполните полями эту структуру
  vector<string> buses;
};

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

struct StopsForBusResponse {
  // Наполните полями эту структуру
  map<string, vector<string>> stops_buses_int;
  vector<string> keys;
};

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

struct AllBusesResponse {
  // Наполните полями эту структуру
  map<string, vector<string>> bus_stops;
};

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

class BusManager {
private:
    map<string, vector<string>> bus_stops;
    map<string, vector<string>> stop_buses;
public:
  void AddBus(const string& bus, const vector<string>& stops) {
    // Реализуйте этот метод
      bus_stops[bus] = stops;
      for(string stop : stops){
          stop_buses[stop].push_back(bus);
      }
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
      BusesForStopResponse out;
      if (stop_buses.count(stop) == 1) {
          out = {stop_buses.at(stop)};
      }
      return out;
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {
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

  AllBusesResponse GetAllBuses() const {
    // Реализуйте этот метод
      AllBusesResponse out = {bus_stops};
      return out;
  }
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}
