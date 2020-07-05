#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "string"
#include "vector"

using namespace std;
// string path = "/home/lemikhovalex/Documents/Coursera/C++_Belt_Series/01_white/04_files_natural_operations/06_Table/";
string path = "";
int main() {
    ifstream input(path + "input.txt");

    int n, m;
    string str;
    if (input.is_open()){
        input >> n >> m;
        getline(input, str, '\n');
    } else{
        cout << "no access to " << path << endl;
    }

    cout << right;
    for(int i = 0; i < n; i++){
    	for (int j = 0; j < m; j++){
    		if(j != m-1){
                getline(input, str, ',');
                cout << right << setw(10) << str;
    			cout << " ";
    		} else{
                getline(input, str, '\n');
                cout << setw(10) << str;

    		}

    	}
    	if(i != n-1){
    	    cout << endl;
    	}
    }

    return 0;
}