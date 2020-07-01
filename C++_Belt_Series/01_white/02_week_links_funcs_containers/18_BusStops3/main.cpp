#include <iostream>
#include "map"
#include "string"
#include "set"

using namespace std;

int main() {
    int n, l;
    cin >> n;
    string stop;
    int enc = 1;
    set<set<string>> set_of_routes;
    set<string> route;
    map<set<string>, int> route_enc;
    for (int i = 0; i < n; i ++){
        cin >> l;
        route = {};
        for (int j = 0; j < l; j ++){
            cin >> stop;
            route.insert(stop);
        }
        if (set_of_routes.count(route) == 1){
            cout << "Already exists for " << route_enc[route] << endl;
        }
        else{
            cout << "New bus " << enc << endl;
            route_enc[route] = enc;
            enc ++;
            set_of_routes.insert(route);
        }
    }
    return 0;
}
