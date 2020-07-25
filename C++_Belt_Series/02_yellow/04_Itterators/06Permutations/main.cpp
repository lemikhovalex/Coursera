#include <iostream>
#include "vector"
#include "algorithm"

using namespace  std;

template<typename T>
void PrintVec(vector<T>& vec){
    bool first = true;
    for(auto i : vec){
        if (first){
            cout << i;
            first = false;
        } else{
            cout << " " << i;
        }
    }
    cout << endl;
}

int main() {
    int n = 0;
    cin >> n;
    vector<int> vec;
    for(int i = 1; i <= n; ++i){
        vec.push_back(i);
    }
    sort(vec.rbegin(), vec.rend());
    PrintVec(vec);
    while(prev_permutation(vec.begin(), vec.end())){
        PrintVec(vec);
    }
    return 0;
}
