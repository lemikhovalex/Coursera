#include <iostream>
#include "string"
#include "vector"
#include "algorithm"
#include "map"

using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        first_names_changes[year] = first_name;
    }
    
    void ChangeLastName(int year, const string& last_name) {
        last_names_changes[year] = last_name;
    }

    string GetFullName(int year) {

        int cyf = get_closest_year_read(first_names_changes, year);
        int cyl = get_closest_year_read(last_names_changes, year);
        //cout << "GetFullName:: cyl=" << cyl << ", cyf= " << cyf << endl;
        string first  = (first_names_changes.count(cyf) == 1) ? first_names_changes[cyf] : "";
        string last = (last_names_changes.count(cyl) == 1) ? last_names_changes[cyl] : "";

        if (first == "" && last == ""){
            return "Incognito";
        }
        if (first == ""){
            return last + " with unknown first name";
        }
        if (last == ""){
            return first + " with unknown last name";
        }
        return first + " " + last;
    }

    string GetFullNameWithHistory(int year) {
        vector<string> fn_hist = get_app_hist(year, first_names_changes);
        vector<string> ln_hist = get_app_hist(year, last_names_changes);
        filter_double_val(fn_hist);
        filter_double_val(ln_hist);

        string fn_out = hist_to_out(fn_hist);
        string ln_out = hist_to_out(ln_hist);

        if (fn_out == "" && ln_out == ""){
            return "Incognito";
        }
        if (fn_out == ""){
            return ln_out + " with unknown first name";
        }
        if (ln_out == ""){
            return fn_out + " with unknown last name";
        }
        return fn_out + " " + ln_out;
    }

private:
    map<int, string> first_names_changes;
    map<int, string> last_names_changes;

    string hist_to_out(const vector<string>& rev_vec){
        int len = rev_vec.size();
        if (len == 0){
            return "";
        }
        if(len == 1){
            return rev_vec[0];
        }
        string out;
        out += rev_vec[len - 1] + " (";
        for(int i = len - 2; i >= 0; i--){
            out += rev_vec[i];
            if(i != 0){
                out += ", ";
            } else{
                out += ")";
            }
        }
        return out;
    }

    vector<string> get_app_hist(int year, map<int, string>& m){
        vector<string> out;
        for(auto ln_app : m){
            if(ln_app.first <= year){
                out.push_back(ln_app.second);
            }
        }
        return out;
    }

    void filter_double_val(vector<string>& vec){
        if(vec.size() >= 1){
            int len = vec.size();
            for(int i = 0; i < len-1; i++){
                if(vec[i] == vec[i+1]){
                    vec.erase(vec.begin() + i + 1);
                    filter_double_val(vec);
                    break;
                }
            }
        }
    }

    int get_closest_year_read(const map<int, string>& m, int year){
        int out = -1;
        for(auto item : m){
            if (item.first <= year) {
                out = item.first;
            } else {
                break;
            }
        }
        if(out == -1){
            out = year;
        }
        return out;
    }
};
/*
int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;

    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;

    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;

    return 0;
}
*/