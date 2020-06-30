#include <iostream>
#include "vector"
using namespace std;

vector<int> Reversed(const vector<int>& v){
    int len = v.size();
    vector<int> out(len);
    for(int i = 0; i < len; i ++){
        out[i] = v[len - 1 - i];
    }
    v.ass
    return out;
}
/*
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
*/