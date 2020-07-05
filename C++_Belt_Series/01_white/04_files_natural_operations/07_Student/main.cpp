#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct FirstName{
    string first_name;
    explicit FirstName(const string& fn){
        first_name = fn;
    }
};

struct LastName{
    string last_name;
    explicit LastName(const string& ln){
        last_name = ln;
    }
};

struct Day{
    int day;
    explicit Day(int d){
        day = d;
    }
};

struct Month{
    int month;
    explicit Month(int m){
        month = m;
    }
};

struct Year{
    explicit Year(int y){
        year = y;
    }
    int year;
};

struct Student {
    explicit Student(const FirstName& fn, const LastName& ln, const Day d, const Month m, const Year y){
        first_name = fn.first_name;
        last_name = ln.last_name;
        day = d.day;
        month = m.month;
        year = y.year;
    }
    string first_name;
    string last_name;

    int day;
    int month;
    int year;
};

int main() {
    int n;
    cin >> n;

    string first_name, last_name;
    int day, month, year;
    vector<Student> students;

    for (size_t i = 0; i < n; ++i) {
        cin >> first_name >> last_name >> day >> month >> year;

        students.push_back(Student{
                FirstName(first_name),
                LastName(last_name),
                Day(day),
                Month(month),
                Year(year)
        });
    }

    int m;
    cin >> m;
    string query;
    int student_number;

    for (int i = 0; i < m; ++i) {
        cin >> query >> student_number;
        --student_number;

        if (query == "name" && student_number >= 0 && student_number < n) {
            cout << students[student_number].first_name << " "
                 << students[student_number].last_name << endl;
        } else if (query == "date" && student_number >= 0 && student_number < n) {
            cout << students[student_number].day << "."
                 << students[student_number].month << "."
                 << students[student_number].year << endl;
        } else {
            cout << "bad request" << endl;
        }
    }

    return 0;
}

