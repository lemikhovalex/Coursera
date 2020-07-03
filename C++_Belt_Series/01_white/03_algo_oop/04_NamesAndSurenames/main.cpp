#include <iostream>
#include "string"
#include "vector"
#include "algorithm"
#include "map"

using namespace std;

class Person {
public:
    int get_closest_year_read(const map<int, string>& m, int year){
        int out = 0;
        if (m.size() == 0 || m.count(year) == 1){
            return year;
        }else{
            int dist = -1;
            for (auto item : m){
                if (((year - item.first < dist) &&(year - item.first > 0) )  || dist < 0){
                    if (year - item.first > 0){
                        dist = year - item.first;
                    }
                }
            }
            out = year - dist;
        }
        return out;
    }

    void ChangeFirstName(int year, const string& first_name) {
        first_names_changes[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        last_names_changes[year] = last_name;
    }

    string GetFullName(int year) {

        int cyf = get_closest_year_read(first_names_changes, year);
        int cyl = get_closest_year_read(last_names_changes, year);
        cout << "GetFullName:: cyl=" << cyl << ", cyf= " << cyf << endl;
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

private:
    map<int, string> first_names_changes;
    map<int, string> last_names_changes;
    // приватные поля
};


int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }
    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }
    cout << "TEST 1 DONE" << endl << endl;
    Person person1;
    person1.ChangeFirstName(65, "p");
    person1.ChangeLastName(67, "s");
    person1.ChangeFirstName(70, "a");
    cout << person1.GetFullName(66);
    return 0;
}
