#include <iostream>
#include "vector"
#include "algorithm"

using namespace std;

template <typename It >
void PrintReverce (It range_begin , It range_end ) {
    if (range_end > range_begin){
        for (auto it = --range_end; it >= range_begin; it--) {
            cout << *it << " ";
        }
    }
}

void PrintVectorPart(const vector<int>& numbers){
    auto result = find_if(
            begin(numbers), end(numbers),
            [](const int& inp) {return inp < 0;});
    if(result == numbers.end()){
        PrintReverce(numbers.begin(), numbers.end());
    } else if (result < numbers.end()){
        PrintReverce(numbers.begin(), result);
    }
}
/*
int main() {
    PrintVectorPart({6, 1, 8, -5, 4});
    cout << endl;
    PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
    cout << endl;
    PrintVectorPart({6, 1, 8, 5, 4});
    cout << endl;
    PrintVectorPart({});
    cout << endl;
    PrintVectorPart({1});
    cout << endl;
    PrintVectorPart({-1});
    cout << endl;
    return 0;
}
*/