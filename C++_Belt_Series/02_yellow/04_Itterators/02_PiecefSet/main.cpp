#include <iostream>
#include "vector"
#include "algorithm"
#include "set"

using namespace std;

template <typename It >
void PrintReverce (It range_begin , It range_end ) {
    if (range_end > range_begin){
        for (auto it = --range_end; it >= range_begin; it--) {
            cout << *it << " ";
        }
    }
}


template <typename It >
void PrintNormal (It range_begin , It range_end ) {
    for (auto it = range_begin ; it != range_end ; ++it) {
        cout << *it << " ";
    }

}

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border){
    auto result = find_if(
            begin(elements), end(elements),
            [border](const T& inp) {return inp > border;});
    vector<T> out;
    for (auto it = result ; it != elements.end() ; ++it) {
        out.push_back(*it);
    }
    return out;
}


int main() {
    for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
        cout << x << " ";
    }
    cout << endl;

    string to_find = "Python";
    cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
    return 0;
}