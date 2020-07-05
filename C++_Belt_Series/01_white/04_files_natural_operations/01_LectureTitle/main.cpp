#include <iostream>
#include <utility>

using namespace std;

struct Specialization{
    string spec;
    explicit Specialization(const string& s){
        spec = s;
    }
};

struct Course{
    string course;
    explicit Course(const string& s){
        course = s;
    }
};

struct Week{
    string week;
    explicit Week(const string& s){
        week = s;
    }
};

struct LectureTitle {

    string specialization;
    string course;
    string week;

    explicit LectureTitle(const Specialization& spec, const Course& c, const Week& w){
        specialization = spec.spec;
        course = c.course;
        week = w.week;
    }

};

int main() {
    // ok
    LectureTitle title(
            Specialization("C++"),
            Course("White belt"),
            Week("4th")
    );
    // not ok
    /*
    LectureTitle title("C++", "White belt", "4th");

    LectureTitle title(string("C++"), string("White belt"), string("4th"));

    LectureTitle title = {"C++", "White belt", "4th"};

    LectureTitle title = {{"C++"}, {"White belt"}, {"4th"}};

    LectureTitle title(
            Course("White belt"),
            Specialization("C++"),
            Week("4th")
    );

    LectureTitle title(
            Specialization("C++"),
            Week("4th"),
            Course("White belt")
    );
     */
    return 0;
}
