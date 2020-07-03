#include <iostream>
#include "vector"
#include "algorithm"

using namespace std;

bool comp_func(string l, string r){
    string left = l;
    string right = r;
    for (auto & c : left){
        c = tolower(c);
    }
    for (auto & c : right){
        c = tolower(c);
    }
    return (left < right);
}

int main() {
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i ++){
        cin >> v[i];
    }
    sort(begin(v), end(v), comp_func);
    for (auto i : v){
        cout << i << " ";
    }
    return 0;
}