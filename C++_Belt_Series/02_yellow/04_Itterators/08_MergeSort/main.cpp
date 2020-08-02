#include <iostream>
#include "vector"
#include "algorithm"

using namespace  std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end);


template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){
    int size = range_end - range_begin;
    // if to small exit
    if (size < 2){
        return;
    }
    // else create new vec
    // split to 2 equal parts
    vector<typename RandomIt::value_type> elements(range_begin, range_end);
    auto sep = elements.begin() + size / 2;
    MergeSort(elements.begin(), sep);
    MergeSort(sep, elements.end());
    // merge these parts
    merge(elements.begin(), sep,
            sep, elements.end(),
            range_begin
            );
}

int main() {
    vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
    MergeSort(begin(v), end(v));
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}

