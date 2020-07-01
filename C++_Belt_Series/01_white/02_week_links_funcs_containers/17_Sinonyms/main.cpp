#include <iostream>
#include "map"
#include "string"
#include "set"

using namespace std;

void add(map<string, set<string>>& syn_dict, string word1, string word2){
    syn_dict[word1].insert(word2);
    syn_dict[word2].insert(word1);
}

void count(map<string, set<string>>& syn_dict, string word1){
    if (syn_dict.count(word1) == 0){
        cout << 0 << endl;
    }else{
        cout << syn_dict[word1].size() << endl;
    }
}

void check(map<string, set<string>>& syn_dict, string word1, string word2){
    if (syn_dict.count(word1) != 0){
        if (syn_dict[word1].count(word2) == 1){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    } else{
        cout << "NO" << endl;
    }
}

int main() {
    map<string, set<string>> syn_dict;
    int n;
    cin >> n;
    string word1, word2;
    string command;
    for (int i = 0; i < n; i++){
        cin >> command;
        if (command == "ADD"){
            cin >> word1 >> word2;
            add(syn_dict, word1, word2);
        }
        if (command == "COUNT"){
            cin >> word1;
            count(syn_dict, word1);
        }
        if (command == "CHECK"){
            cin >> word1 >> word2;
            check(syn_dict, word1, word2);
        }
    }
    return 0;
}
