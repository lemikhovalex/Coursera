#include <iostream>
#include "string"
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
/*
int main() {
    string s = "volchek";
    cout << "string ==" << s << endl;
    cout << "Is palindrom ?" << IsPalindrom(s) << endl;
    return 0;
}
*/