#include <iostream>
#include "vector"
#include "map"

using namespace std;

template <typename T>
T Sqr(T const x);

template <typename First>
vector<First>Sqr(const vector<First>& p1);

template <typename First, typename Second>
pair<First, Second>Sqr(const pair <First , Second >& p1);

template <typename First, typename Second>
map<First, Second>Sqr(const map<First, Second>& lhs);

template <typename First>
vector<First>Sqr(const vector<First>& p) {
    vector<First> out(p.size());
    for(int i = 0; i < p.size(); i ++){
        out[i] = Sqr(p[i]);
    }
    return out;
}

template <typename First, typename Second>
pair<First, Second>Sqr(const pair <First , Second >& p) {
    First f = Sqr(p.first);
    Second s = Sqr(p.second);
    return make_pair(f, s);
}

template <typename First, typename Second>
map<First, Second>Sqr(const map<First, Second>& lhs){
    map<First, Second> out;
    for (auto& [key, value] : lhs){
        out[key] = Sqr(value);
    }
    return out;
};

template <typename T>
T Sqr(T const x) {
    return x * x;
}

int main() {
    vector<int> v {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
            {4, {2, 2}},
            {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto &x : Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
    cout << endl << endl;
    vector<double> pair = {2, 2.25};
    cout << Sqr(pair)[0];
    return 0;
}
