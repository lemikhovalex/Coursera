#include <iostream>
#include <sstream>
#include "set"
#include "vector"
#include "map"
#include <iomanip>
#include <string.h>

using namespace std;

class Date {
public:
    int GetYear() const{
        return year;
    }
    int GetMonth() const{
        return month;
    }
    int GetDay() const{
        return day;
    }

    Date()= default;

    Date(int y, int m, int d){
        if (m < 1 || m > 12){
            throw runtime_error("Month value is invalid: " + to_string(m) + '\n');
        }
        if( d < 1 || d > 31){
            throw runtime_error("Day value is invalid: " + to_string(d) + '\n');
        }
        if( y < 0){
            throw runtime_error("Year sucks");
        }

        year = y;
        month = m;
        day = d;
    }

private:
    int year{};
    int month{};
    int day{};
};

bool operator<(const Date& lhs, const Date& rhs);

void ensure_next_symb(istream& em_cin){
    if (em_cin.peek() != '-') {
        throw runtime_error("DayFormat issue");
    }
    em_cin.ignore(1);
}

istream& operator>>(istream& stream, Date& d){
    // 0001-01-01
    //y-m-d
    string input;
    stream >> input;
    stringstream em_cin(input); // got all string, and locally emulate cin as em_cin

    int day, month, year;
    try{
        em_cin >> year;
        ensure_next_symb(em_cin);
        em_cin >> month;

        ensure_next_symb(em_cin);
        em_cin >> day;
        if (em_cin.peek() != -1) {
            throw runtime_error("DayFormat issue");
        }
        d = Date(year, month, day);
    }
    catch (runtime_error& re) {
        if (strcmp(re.what(), "DayFormat issue") == 0){
            throw runtime_error("Wrong date format: " + input + '\n');
        }
        else{
            /*
            cout << strcmp(re.what(), "DayFormat issue") << endl;
            cout << re.what() << endl;
            cout << "DayFormat issue" << endl;
             */
            throw re;
        }
    }

    return stream;
}

bool operator < (const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() == rhs.GetYear()) {
        if (lhs.GetMonth() == rhs.GetMonth()) {
            return lhs.GetDay() < rhs.GetDay();
        }
        return lhs.GetMonth() < rhs.GetMonth();
    }
    return lhs.GetYear() < rhs.GetYear();
}

class Database {
public:
    void AddEvent(const Date& date, const string& event){
        DB[date].insert(event);
    }

    bool DeleteEvent(const Date& date, const string& event){
        if ((DB.count(date) == 1) && (DB[date].erase(event) == 1)){
            cout << "Deleted successfully" << endl;
            return true;
        } else{
            cout << "Event not found" << endl;
            return false;
        }
    }

    int  DeleteDate(const Date& date){
        if (DB.count(date) == 1){
            int count = DB.at(date).size();
            DB.erase(date);
            cout << "Deleted " << count << " events" << endl;
            return true;
        } else{

            cout << "Deleted 0 events" << endl;
            return false;
        }
    }

    void Find(const Date& date) const{
        if (DB.count(date) == 1){
            for(const auto& ev : DB.at(date)){
                cout << ev << endl;
            }
        }
    }

    void Print() const{
        if (! DB.empty()){
            for (const auto& date_evs : DB){
                for (auto ev : date_evs.second){
                    cout << setw(4) << setfill('0');
                    cout << date_evs.first.GetYear() << "-";
                    cout << setw(2) << setfill('0');
                    cout << date_evs.first.GetMonth() << "-";
                    cout << setw(2) << setfill('0');
                    cout << date_evs.first.GetDay() << " ";
                    cout << ev << endl;
                }
            }
        }
    }

    void GetRequest(const string& line){
        stringstream em_cin(line);
        string comm;
        Date date;
        string ev = "";
        em_cin >> comm; // >> date >> ev.event;
        if (comm == ""){
            return;
        }
        if (comm == "Add" || comm == "Del" || comm == "Find" || comm == "Print"){
            if(comm == "Add"){
                em_cin >> date >> ev;
                AddEvent(date, ev);
            } else if (comm == "Del"){
                em_cin >> date;
                if (em_cin.peek() == -1){
                    DeleteDate(date);
                } else{
                    em_cin >> ev;

                    DeleteEvent(date, ev);
                }
            } else if (comm == "Find"){
                em_cin >> date;
                Find(date);
            }else if (comm == "Print"){
                Print();
            }
        } else{
            throw runtime_error("Unknown command: " + comm + '\n');
        }
    }

private:
    map<Date, set<string>> DB;
};


int main() {
    Database db;

    string command;
    while (getline(cin, command)) {
        try{
            db.GetRequest(command);
        } catch (exception& ex) {
            cout << ex.what();
        }
    }

    return 0;
}