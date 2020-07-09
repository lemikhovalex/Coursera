#include <iostream>
#include "vector"
using namespace std;

int main() {
    int n;
    int64_t sum = 0;
    cin >> n;
    vector<int> temps(n);
    for(int i = 0; i < n; i++){
        cin >> temps[i];
        sum += temps[i];
    }
    vector<int> out_ind;
    for(int i = 0; i < n; i++){
        int64_t temp = n * temps[i];
        if (temp > sum){
            out_ind.push_back(i);
        }
    }
    cout << out_ind.size() << endl;
    for(auto ind : out_ind){
        cout << ind << " ";
    }
    return 0;
}