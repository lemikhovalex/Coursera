#include <iostream>
#include "vector"
#include "algorithm"

using namespace std;

bool comp_func(int i, int j){
    return (abs(i) < abs(j));
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i ++){
        cin >> v[i];
    }
    sort(begin(v), end(v),[](int l, int r) { return abs(l) < abs(r); });
    for (auto i : v){
        cout << i << " ";
    }
    return 0;
}
