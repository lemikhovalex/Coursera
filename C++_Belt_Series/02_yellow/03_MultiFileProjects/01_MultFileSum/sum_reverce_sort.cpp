//
// Created by lemikhovalex on 16.07.2020.
//
#include "sum_reverse_sort.h"
#include "algorithm"

int Sum(int x, int y){
    return  x + y;
}

string Reverse(string s){
    string out = s;
    for (int i = 0; i < s.length(); ++i){
        out[i] = s[s.size() - 1 - i];
    }
    return out;
}

void Sort(vector<int>& nums){
    sort(begin(nums), end(nums));
}

