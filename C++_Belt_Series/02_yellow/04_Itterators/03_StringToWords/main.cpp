#include <iostream>
#include "vector"
#include "algorithm"

using namespace std;

template<typename T>
void PushBackSubstr(vector<string>& dest, T begin, T end){
    if(*begin != ' '){
        string s = "";
        for(auto it = begin; it < end; ++it){
            s.push_back(*it);
        }
        dest.push_back(s);
    }

}

vector<string> SplitIntoWords(const string& s){
    vector<string> out;
    auto beg = s.begin();
    auto end = s.begin();
    while(end != s.end()){
        if(*end == ' '){
            PushBackSubstr(out, beg, end);
            ++end;
            beg = end;
        } else{
            ++end;
        }
    }
    if(beg != s.end()){
        PushBackSubstr(out, beg, end);
    }
    return out;
}

int main() {
    // string s = "C Cpp Java Python";
    string s = "llll ppp  ";
    vector<string> words = SplitIntoWords(s);
    cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            cout << "/";
        }
        cout << *it;
    }
    cout << endl;

    return 0;
}
