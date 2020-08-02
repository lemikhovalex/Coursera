#include <iostream>
#include "set"
#include "vector"
#include "algorithm"

using namespace std;

struct Prefix{
    string p;
    Prefix(string x){
        p = x;
    }
};

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
        RandomIt range_begin, RandomIt range_end,
        const string& prefix);

bool operator<(const string & lhs, const Prefix & rhs){
    if (rhs.p.size() < lhs.size()){
        return lhs.substr(0, rhs.p.size()) < rhs.p;
    }
    return lhs < rhs.p;
}

bool operator<(const Prefix & lhs, const string & rhs){
    if (lhs.p.size() < rhs.size()){
        return lhs.p < rhs.substr(0, lhs.p.size());;
    }
    return lhs.p < rhs;
}

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
        RandomIt range_begin, RandomIt range_end,
        const string& prefix){
    //auto out_l = find_if(range_begin, range_end, [prefix](const string x){return x[0] == prefix;});
    //auto out_r = find_if(range_begin, range_end, [prefix](const string x){return x[0] >  prefix;});

    auto out_l = lower_bound(range_begin, range_end, Prefix(prefix));
    auto out_r = upper_bound(range_begin, range_end, Prefix(prefix));

    if (out_l != range_end){
        return {out_l, out_r};
    } else{
        return {out_r, out_r};
    }
    return {out_l, out_r};

}

int main() {
    const vector<string> sorted_strings = {"moscow", "motovilikha", "murmansk"};

    const auto mo_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
    for (auto it = mo_result.first; it != mo_result.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    const auto mt_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
    cout << (mt_result.first - begin(sorted_strings)) << " " <<
         (mt_result.second - begin(sorted_strings)) << endl;

    const auto na_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
    cout << (na_result.first - begin(sorted_strings)) << " " <<
         (na_result.second - begin(sorted_strings)) << endl;
    cout << ("mo" < "moscow") << endl;
}