#include <iostream>
#include "map"
#include "string"

using namespace std;

map<char, int> BuildCharCounters(string word){
    map<char, int> out;
    for(auto ch : word){
        out[ch]++;
    }
    return out;
}

int main() {
    int n;
    cin >> n;
    string word1, word2;
    for(int i = 0; i < n; i++){
        cin >> word1 >> word2;
        if(BuildCharCounters(word1) == BuildCharCounters(word2)) {
            cout << "YES";
        } else{
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}
