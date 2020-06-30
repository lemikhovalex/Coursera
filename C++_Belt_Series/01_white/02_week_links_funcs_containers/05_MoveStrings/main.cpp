#include <iostream>
#include "string"
#include "vector"
using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination)
{
    for(auto s : source){
        destination.push_back(s);
    }
    source.clear();
}
/*
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
*/