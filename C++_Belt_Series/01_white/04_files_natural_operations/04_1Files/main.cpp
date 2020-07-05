#include <iostream>
    #include <fstream>

using namespace std;

int main() {
    string line;
    ifstream input("input.txt");
    if (input.is_open()){
        cout << "got access" << endl;
        while (getline(input, line)) {
            cout << line << endl;
        }
    } else{
        cout << "no acces";
    }
    return 0;
}
