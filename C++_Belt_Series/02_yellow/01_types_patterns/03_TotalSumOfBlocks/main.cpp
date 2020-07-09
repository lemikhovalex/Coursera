#include <iostream>
#include "vector"
using namespace std;

int main() {
    int n, r;
    cin >> n >> r;
    unsigned long int x, y, z;
    unsigned long int m = 0;
    for(unsigned int i = 0; i < n; i++){
        cin >> x >> y >> z;
        m += x * y * z * r;
    }
    cout << m;
}