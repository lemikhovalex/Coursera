#include <iostream>
#include "map"
#include "string"
#include "set"

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> out;
    for (auto item : m){
        out.insert(item.second);
    }
    return out;
}

/*
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
*/