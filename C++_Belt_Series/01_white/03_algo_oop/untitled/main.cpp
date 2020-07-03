#include <iostream>
#include "map"
#include "string"

using namespace std;

int get_closest_year(map<int, Names> year_names, int year){
    int out = 0;
    if (year_names.size() == 0 || year_names.count(year) == 0){
        return year;
    }else{
        int dist = -1;
        for (auto item : year_names){
            if (year - item.first < dist || dist == -1){
                dist = year - item.first;
            }
        }
        out = year - dist;
    }
    return out;
}

int main() {
    map<int, string> m;
    m[1997] = "lol";
    cout << m.count(1996);
    return 0;
}
