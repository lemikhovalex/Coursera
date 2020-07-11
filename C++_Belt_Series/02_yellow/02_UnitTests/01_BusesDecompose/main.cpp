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
    string command;
    int inp_count = 0;
    string inp_str1, inp_str2;
    vector<string> inps;
    is >> command;if (command == "NEW_BUS"){
        q.type == QueryType::NewBus;
        cin >> q.bus >> inp_count;
        inps = {};
        for (int j = 0; j < inp_count; j ++){
            cin >> inp_str2;
            q.stops.push_back(inp_str2);
        }
    }
    if (command == "BUSES_FOR_STOP"){
        q.type == QueryType::BusesForStop;
        cin >> q.stop;
    }
    if (command == "STOPS_FOR_BUS"){
        q.type == QueryType::StopsForBus;
        cin >> q.bus;
    }
    if (command == "ALL_BUSES"){
        q.type == QueryType::AllBuses;
    }
  return is;
}

struct BusesForStopResponse {
  // Наполните полями эту структуру
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
  // Реализуйте эту функцию
  return os;
}

struct StopsForBusResponse {
  // Наполните полями эту структуру
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
  // Реализуйте эту функцию
  return os;
}

struct AllBusesResponse {
  // Наполните полями эту структуру
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
  // Реализуйте эту функцию
  return os;
}

class BusManager {
private:

    map<string, vector<string>> bus_stops;
    map<string, vector<string>> stop_buses;
public:
  void AddBus(const string& bus, const vector<string>& stops) {
    // Реализуйте этот метод
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
      if (stop_buses.count(stop) == 0){
          cout << "No stop";
      }else{
          for(string bus : stop_buses.at(stop)){
              cout << bus << " ";
          }
      }
      cout << endl;
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {
    // Реализуйте этот метод
      if (bus_stops.count(bus) == 0){
          cout << "No bus" << endl;
      }else{
          for(auto stop_for_bus : bus_stops.at(bus)){
              cout << "Stop " << stop_for_bus << ": ";
              if (stop_buses.at(stop_for_bus).size() <= 1) {
                  cout << "no interchange" << endl;
              }else{
                  for (auto bus_for_stop : stop_buses.at(stop_for_bus)){
                      if (bus_for_stop != bus){
                          cout << bus_for_stop << " ";
                      }
                  }
                  cout << endl;
              }
          }
      }
  }

  AllBusesResponse GetAllBuses() const {
    // Реализуйте этот метод
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
