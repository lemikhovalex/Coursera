#include <iostream>
#include "vector"
#include "algorithm"
#include "set"

using namespace std;

bool f(int x){
    return x > 3;
}

void check_res(const vector<int>& v, const vector<int>& exp){
    cout << " Expected" << endl << "   ";
    for(int it : exp){
        cout << " " << it ;
    }
    cout << endl;
    cout << " Got" << endl << "   ";
    for(int it : v){
        cout << " " << it;
    }

    cout << endl << endl << endl;
    cout << endl;

}

int main() {
    set<int> s = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> exp = {1, 2, 3};
    vector<int> v;
    cout << "1";
    remove_copy_if(begin(s), end(s), back_inserter(v), f);
    check_res(v, exp);

    cout << "2";
    v.assign(begin(s), end(s));
    auto it = partition(begin(v), end(v), f);
    v.erase(it, end(v));
    check_res(v, exp);


    cout << "3" << endl;
    /*
    auto it1 = remove_if(begin(s), end(s),
                        [](int x) { return !f(x); });
    copy(it1, end(s), back_inserter(v));
    check_res(v, exp);
     */
    cout << "4";
    v = {};
    copy_if(begin(s), end(s), back_inserter(v),
            [](int x) { return !f(x); });
    check_res(v, exp);

    cout << "5";
    v = {};
    copy_if(begin(s), end(s), back_inserter(v), f);
    check_res(v, exp);

    cout << "6";
    v = {};
    v.assign(begin(s), end(s));
    sort(begin(v), end(v),
         [](int lhs, int rhs) { return f(lhs) > f(rhs); });
    auto it1 = partition_point(begin(v), end(v), f);
    v.erase(begin(v), it1);
    check_res(v, exp);

    cout << "7";
    v = {};
    vector<int> garbage;
    partition_copy(
            begin(s), end(s),
            back_inserter(garbage), back_inserter(v), f);
    check_res(v, exp);

    cout << "8";
    v = {};
    v.assign(begin(s), end(s));
    sort(begin(v), end(v),
         [](int lhs, int rhs) { return f(lhs) > f(rhs); });
    auto it3 = partition_point(begin(v), end(v), f);
    v.erase(it3, end(v));
    check_res(v, exp);

    cout << "9";
    v = {};
    remove_copy_if(begin(s), end(s), back_inserter(v),
                   [](int x) { return !f(x); });
    check_res(v, exp);

    cout << "10";
    v = {};
    v.assign(begin(s), end(s));
    auto it4 = remove_if(begin(v), end(v),
                        [](int x) { return !f(x); });
    v.erase(it4, end(v));
    check_res(v, exp);


    cout << "11";
    cout << endl;
    /*
    v = {};
    auto it5 = partition(begin(s), end(s), f);
    copy(it5, end(s), back_inserter(v));
    check_res(v, exp);
     */

    cout << "12";
    v = {};
    v.assign(begin(s), end(s));
    auto it6 = partition(begin(v), end(v), f);
    v.erase(begin(v), it6);
    check_res(v, exp);

    cout << "13";
    v = {};
    garbage = {};
    partition_copy(
            begin(s), end(s),
            back_inserter(v), back_inserter(garbage), f);
    check_res(v, exp);

    cout << "14";
    v = {};
    v.assign(begin(s), end(s));
    it = remove_if(begin(v), end(v), f);
    v.erase(it, end(v));
    check_res(v, exp);

    // 2nd task - complie check

    vector<int> vec;
    auto vector_begin = begin(vec);
    auto vector_end = end(vec);

    string str;
    auto string_begin = begin(str);
    auto string_end = end(str);

    s = {};
    auto set_begin = begin(s);
    auto set_end = end(s);
    /* no
    auto res = is_heap(set_begin, set_end);
    */
    /* no
    auto res = is_heap(set_begin, set_end);
    */
    /* no
    partial_sum(set_begin, set_end, back_inserter(vec));
    */
    /* no
    auto res = accumulate(set_begin, set_end, 0);
    */

    auto res = is_permutation(set_begin, set_end, vector_begin);
    /*
    partial_sum(set_begin, set_end, vector_begin);
    */
    /* no
    auto res = accumulate(vector_begin, vector_end, 0);
    */
    /* no
    auto res1 = is_permutation(set_begin, set_end, back_inserter(vec));
    */
    /* no
    auto res2 = is_permutation(set_begin, set_end, back_inserter(vec));
    */

    auto res3 = next_permutation(string_begin, string_end);
    /*
    partial_sum(vector_begin, vector_end, set_begin);
    */
    auto res4 = is_heap(string_begin, string_end);
    return 0;
}