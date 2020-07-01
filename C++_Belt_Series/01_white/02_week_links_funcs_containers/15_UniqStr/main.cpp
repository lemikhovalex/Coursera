#include <iostream>
#include "set"
#include "string"
using namespace std;

int main() {
    int n;
    cin >> n;
    string str;
    set<string> se;
    for(int i = 0; i < n; i++){
        cin >> str;
        se.insert(str);
    }
    cout << se.size();
    return 0;
}
