#include <iostream>
#include "vector"
using namespace std;

int main() {
    int n;
    double sum = 0;
    cin >> n;
    vector<int> temps(n);
    for(int i = 0; i < n; i++){
        cin >> temps[i];
        sum += temps[i];
    }
    sum /= n;
    vector<int> out_ind;
    for(int i = 0; i < n; i++){
        if (temps[i]  > sum){
            out_ind.push_back(i);
        }
    }
    cout << out_ind.size() << endl;
    for(auto ind : out_ind){
        cout << ind << " ";
    }
    return 0;
}
