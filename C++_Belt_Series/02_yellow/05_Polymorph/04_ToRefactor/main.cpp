#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Man {
public:
    Man(const string & s): job(s){}

    string Name;
    virtual void Walk(string destination){
        cout << job << ": " << Name << " walks to: " << destination << endl;
    }

    const string job;
};

class Student : public Man {
public:

    Student(string name, string favouriteSong): Man("Student"){
        Name = name;
        FavouriteSong = favouriteSong;
    }

    void Learn() {
        cout << "Student: " << Name << " learns" << endl;
    }

    void Walk(string destination) override {
        cout << "Student: " << Name << " walks to: " << destination << endl;
        cout << "Student: " << Name << " sings a song: " << FavouriteSong << endl;
    }

    void SingSong() {
        cout << "Student: " << Name << " sings a song: " << FavouriteSong << endl;
    }

public:
    string FavouriteSong;
};


class Teacher : public Man {
public:

    Teacher(string name, string subject): Man("Teacher"){
        Name = name;
        Subject = subject;
    }

    void Teach() {
        cout << "Teacher: " << Name << " teaches: " << Subject << endl;
    }

public:
    string Subject;
};


class Policeman :public Man {
public:
    Policeman(string name) : Man("Policeman") {
        Name = name;
    }

    void Check(Man m) {
        cout << this->job << ": " << Name << " checks " << m.job << ". " << m.job << "'s name is: " << m.Name << endl;
    }

public:
    string Name;
};


void VisitPlaces(Man m, vector<string> places) {
    for (auto p : places) {
        m.Walk(p);
    }
}


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}