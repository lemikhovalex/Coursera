#include <iostream>
#include "vector"
#include "map"

using namespace std;

int main() {
    int n, l;
    cin >> n;
    vector<string> inp_stops;
    string stop;
    bool exist_route_flag = false;
    int route_counter = 1;
    int exists_for;
    map<int, vector<string>> routes;
    for (int i = 0; i < n; i ++){
        cin >> l;
        inp_stops = {};
        for (int j = 0; j < l; j++){
            cin >> stop;
            inp_stops.push_back(stop);
        }

        for (auto route : routes){
            if (route.second == inp_stops){
                exist_route_flag = true;
                exists_for = route.first;
            }
        }
        if (!exist_route_flag){
            routes[route_counter] = inp_stops;
            cout << "New bus " << route_counter << endl;
            route_counter ++;
        } else{
            cout << "Already exists for " << exists_for << endl;
        }
        exist_route_flag = false;
    }
    return 0;
}

