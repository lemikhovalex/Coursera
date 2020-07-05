#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "string"
#include "vector"

using namespace std;
string path = "/home/lemikhovalex/Documents/Coursera/C++_Belt_Series/01_white/04_files_natural_operations/06_Table/";

int main() {
    ifstream input(path + "input.txt");

    int n, m;
    string str;
    if (input.is_open()){
        input >> n >> m >> str;
    } else{
        cout << "no access to " << path << endl;
    }

    cout << left;
    for(int i = 0; i < n; i++){
    	for (int j = 0; j < m; j++){
    		getline(input, str, ',');
    		cout << left;
    		cout << setw(10) << str;
    		if(j != m-1){
    			cout << " ";
    		}

    	}
    }

    return 0;
}