#include <iostream>
#include "string"
#include "vector"
#include "algorithm"
#include "map"

using namespace std;

class Person {
public:
    Person(const string fn, const string ln, const int year){
        b_year = year;
        first_names_changes[year] = (fn);
        last_names_changes[year] = (ln);
    }

    void ChangeFirstName(int year, const string& first_name) {
        if(year >= b_year){
            first_names_changes[year] = first_name;
        }
    }

    void ChangeLastName(int year, const string& last_name) {
        if(year >= b_year){
            last_names_changes[year] = last_name;
        }
    }

    string GetFullName(int year) const {
        if(year < b_year){
            return  "No person";
        }
        int cyf = get_closest_year_read(first_names_changes, year);
        int cyl = get_closest_year_read(last_names_changes, year);
        //cout << "GetFullName:: cyl=" << cyl << ", cyf= " << cyf << endl;
        string first  = (first_names_changes.count(cyf) == 1) ? first_names_changes.at(cyf) : "";
        string last = (last_names_changes.count(cyl) == 1) ? last_names_changes.at(cyl) : "";

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

    string GetFullNameWithHistory(int year) const {
        if(year < b_year){
            return  "No person";
        }

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
    int b_year;

    string hist_to_out(const vector<string>& rev_vec) const {
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

    vector<string> get_app_hist(int year, const map<int, string>& m) const{
        vector<string> out;
        for(auto ln_app : m){
            if(ln_app.first <= year){
                out.push_back(ln_app.second);
            }
        }
        return out;
    }

    void filter_double_val(vector<string>& vec) const{
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

    int get_closest_year_read(const map<int, string>& m, int year)const {
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

int main() {
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
}