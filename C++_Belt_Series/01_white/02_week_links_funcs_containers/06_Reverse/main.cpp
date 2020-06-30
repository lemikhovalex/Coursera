#include <iostream>
#include "vector"
using namespace std;

void Reverse(vector<int>& v){
    int len = v.size();
    int tmp = 0;
    for(int i = 0; i < len / 2; i ++){
        tmp = v[i];
        v[i] = v[len - 1 - i];
        v[len - 1 - i] = tmp;
    }
}
/*
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
*/