#include <iostream>
#include "vector"
#include "string"
using namespace std;

void worry(vector<int>& q, int input){
    q[input] = 1;
}

void quiet(vector<int>& q, int input){
    q[input] = 0;
}

void come(vector<int>& q, int input){
    if (input > 0){
        for(int i = 0; i < input; i++) {
            q.push_back(0);
        }
    }else{
        q.resize(q.size() + input);

    }
}

void print_worry_count(const vector<int>& q){
    int sum = 0;
    for(auto x : q){
        sum += x;
    }
    cout << sum << endl;
}

int main() {
    int n;
    vector<int> q;
    int input;
    cin >> n;
    string command;
    for (int i = 0; i < n; i++){
        cin >> command;
        if (command == "WORRY" || command == "QUIET" || command == "COME"){
            cin >> input;
        }
        if (command == "WORRY"){
            worry(q, input);
        }
        if (command == "QUIET"){
            quiet(q, input);
        }
        if (command == "COME"){
            come(q, input);
        }
        if (command =="WORRY_COUNT"){
            print_worry_count(q);
        }

    }
    return 0;
}
