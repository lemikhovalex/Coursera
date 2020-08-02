#include <iostream>
#include "vector"
#include "algorithm"
#include "set"

using namespace  std;

set<int>::const_iterator FindNearestElement(
        const set<int>& numbers,
        int border);

set<int>::const_iterator FindNearestElement(
        const set<int>& numbers,
        int border){
    auto out_upper = numbers.upper_bound(border);
    auto out_lower = numbers.lower_bound(border);

    if (out_lower != numbers.begin() && *out_lower != border){
        -- out_lower;
    }

    //cout << "Boarder =" << border << ", lower = " << *out_lower << ", upper = " << *out_upper << endl;

    if(abs(*out_upper - border) < abs(*out_lower - border)){
        return out_upper;
    } else{
        return out_lower;
    }
    return out_lower;
}

int main() {
    set<int> numbers = {1, 4, 6};
    cout <<
         *FindNearestElement(numbers, 0) << " " <<
         *FindNearestElement(numbers, 3) << " " <<
         *FindNearestElement(numbers, 5) << " " <<
         *FindNearestElement(numbers, 6) << " " <<
         *FindNearestElement(numbers, 100) << endl;

    set<int> empty_set;

    cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
    return 0;
}
