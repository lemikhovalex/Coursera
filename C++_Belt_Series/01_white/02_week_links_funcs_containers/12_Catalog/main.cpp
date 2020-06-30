#include <iostream>
#include "map"
#include "string"

using namespace std;

void change_cappital(map<string, string>& cat, string country, string new_capital){
    if (cat.count(country) == 0) {
        cout << "Introduce new country " << country << " with capital " << new_capital << endl;
        cat[country] = new_capital;
    }else {
        if (cat[country] == new_capital) {
            cout << "Country " << country << " hasn't changed its capital" << endl;
        } else {
            cout << "Country " << country << " has changed its capital from " << cat[country] << " to " << new_capital;
            cout << endl;
            cat[country] = new_capital;
        }
    }
}


void rename(map<string, string>& cat, string old_country_name, string new_country_name){
    if(old_country_name == new_country_name ||  cat.count(old_country_name) == 0 || cat.count(new_country_name) != 0){
        cout << "Incorrect rename, skip" << endl;
    }else{
        cout << "Country " << old_country_name << " with capital " << cat[old_country_name];
        cout <<" has been renamed to " << new_country_name << endl;

        cat[new_country_name] = cat[old_country_name];
        cat.erase(old_country_name);
    }
}


void about(map<string, string>& cat, string country){
    if (cat.count(country) == 0 ) {
        cout << "Country " << country << " doesn't exist" << endl;
    }else{
        cout << "Country " << country << " has capital " << cat[country] << endl;
    }
}


void dump(map<string, string>& cat){
    if (cat.size() == 0){
        cout << "There are no countries in the world" << endl;
    }
    else{
        for (auto country : cat){
            cout << country.first << "/" << country.second << endl;
        }
    }
}


int main() {
    int n;
    cin >> n;
    map<string, string> catalog;
    string command, input1, input2;
    for(int i = 0; i < n; i ++){
        cin >> command;
        if (command == "CHANGE_CAPITAL"){
            cin >> input1 >> input2;
            change_cappital(catalog, input1, input2);
        }
        if (command =="RENAME"){
            cin >> input1 >> input2;
            rename(catalog, input1, input2);
        }
        if (command == "ABOUT"){
            cin >> input1;
            about(catalog, input1);
        }
        if (command == "DUMP"){
            dump(catalog);
        }
    }
    return 0;
}
