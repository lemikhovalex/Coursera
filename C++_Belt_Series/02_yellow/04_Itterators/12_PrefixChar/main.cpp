#include <iostream>
#include "set"
#include "vector"
#include "algorithm"

using namespace std;

struct FirstLetter{
    char fl;
    FirstLetter(char x){
        fl = x;
    }
};

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
        RandomIt range_begin, RandomIt range_end,
        char prefix);

bool operator<(const string & lhs, const FirstLetter & rhs){
    return lhs[0] < rhs.fl;
}

bool operator<(const FirstLetter & rhs, const string & lhs){
    return rhs.fl < lhs[0];
}

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
        RandomIt range_begin, RandomIt range_end,
        char prefix){
    //auto out_l = find_if(range_begin, range_end, [prefix](const string x){return x[0] == prefix;});
    //auto out_r = find_if(range_begin, range_end, [prefix](const string x){return x[0] >  prefix;});

    auto out_l = lower_bound(range_begin, range_end, FirstLetter(prefix));
    auto out_r = upper_bound(range_begin, range_end, FirstLetter(prefix));

    if (out_l != range_end){
        return {out_l, out_r};
    } else{
        return {out_r, out_r};
    }
    return {out_l, out_r};

}

int main() {

    const vector<string> sorted_strings = {"moscow", "murmansk", "vologda"};

    const auto m_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
    for (auto it = m_result.first; it != m_result.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    const auto p_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
    cout << (p_result.first - begin(sorted_strings)) << " " <<
         (p_result.second - begin(sorted_strings)) << endl;

    const auto z_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
    cout << (z_result.first - begin(sorted_strings)) << " " <<
         (z_result.second - begin(sorted_strings)) << endl;
    return 0;
}