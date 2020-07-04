#include <iostream>

using namespace std;

struct Specialization{
    string spec;
    explicit Specialization(string s){
        spec = s;
    }
};

struct Course{
    string course;
    explicit Course(string s){
        course = s;
    }
};

struct Week{
    string week;
    explicit Week(string s){
        week = s;
    }
};

struct LectureTitle {
    explicit LectureTitle(Specialization spec, Course c, Week w){
        specialization = spec.spec;
        course = c.course;
        week = w.week;
    }
    string specialization;
    string course;
    string week;
};
/*
int main() {
    // ok
    LectureTitle title(
            Specialization("C++"),
            Course("White belt"),
            Week("4th")
    );
    // not ok

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
    return 0;
}
*/