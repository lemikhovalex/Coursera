#include <iostream>
#include <sstream>
#include "set"
#include "vector"
#include "map"
#include <iomanip>

using namespace std;

class Date {
public:
    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;
};

class Event{
public:
    Event(const string& e){
        event = e;
    }
    string event;
};

bool operator<(const Date& lhs, const Date& rhs);

class Database {
public:
    void AddEvent(const Date& date, const string& event){
        DB[date].insert(Event(event));
    }

    bool DeleteEvent(const Date& date, const string& event){
        if ((DB.count(date) == 1) && (DB[date].erase(Event(event)) == 1)){
            cout << "Deleted successfully" << endl;
            return true;
        } else{
            cout << "Event not found" << endl;
            return false;
        }
    }

    int  DeleteDate(const Date& date){
        if (DB.count(date) == 1){
            DB.erase(date);
            cout << "Deleted successfully" << endl;
            return true;
        } else{
            cout << "Event not found" << endl;
            return false;
        }
    }

    void Find(const Date& date) const{
        if (DB.count(date) == 1){
            for(auto ev : DB.at(date)){
                cout << ev.event << endl;
            }
        }
    }

    void Print() const{
        if (DB.size() > 0){
            for (auto date_evs: DB){
                for (auto ev : date_evs.second){
                    cout << setw(4) << setfill('0');
                    cout << date_evs.first.GetYear() << "-";
                    cout << setw(2) << setfill('0');
                    cout << date_evs.first.GetMonth() << "-";
                    cout << setw(2) << setfill('0');
                    cout << date_evs.first.GetDay() << endl;
                }
            }
        }
    }

private:
    map<Date, set<Event>> DB;
};

int main() {
    Database db;

    string command;
    while (getline(cin, command)) {
    }

    return 0;
}