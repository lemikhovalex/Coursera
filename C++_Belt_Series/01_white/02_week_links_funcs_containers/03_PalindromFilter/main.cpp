#include <iostream>
#include "string"
#include "vector"

using namespace std;

bool IsPalindrom(string s){
    int len = s.length();
    if (len <= 1){
        return true;
    }
    else{
        if (s[0] == s[len - 1]){
            return IsPalindrom(s.substr(1, s.size() - 2));
        } else{
            return false;
        }
    }
}

vector<string> PalindromFilter(vector<string> strs, int minLength){
    vector<string> out = {};
    for (auto s : strs){
        if (IsPalindrom(s) && s.length() >= minLength){
            out.push_back(s);
        }
    }
    return out;
}

/*
int main() {
    int m = 5;
    vector<string> strs = {"abacaba", "aba"};
    vector<string> for_pr = PalindromFilter(strs, m);
    for (auto s : for_pr){
        cout << s << endl;
    }
    return 0;
}
*/