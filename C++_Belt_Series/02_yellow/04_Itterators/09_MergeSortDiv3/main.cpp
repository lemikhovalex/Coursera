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
    auto sep1 = elements.begin() + size / 3;
    auto sep2 = elements.begin() + 2 * size / 3;
    MergeSort(elements.begin(), sep1);
    MergeSort(sep1, sep2);
    MergeSort(sep2, elements.end());
    // merge these parts
    // the 3rd part in tmp
    vector<typename RandomIt::value_type> temp_vec;
    // and 1st and 2nd are inserted back already merged
    merge(elements.begin(), sep1,
          sep1, sep2,
          back_inserter(temp_vec)
    );
    // lastly merge temp
    merge(temp_vec.begin(), temp_vec.end(),
          sep2, elements.end(),
          range_begin
    );
}

int main() {
    vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
    MergeSort(begin(v), end(v));
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}

