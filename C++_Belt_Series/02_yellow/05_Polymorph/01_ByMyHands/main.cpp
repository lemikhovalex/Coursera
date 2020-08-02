#include <iostream>
#include "string"
using namespace std;

class Animal {
public:
    // ваш код
    Animal(const string & t = "Animal")
    :Name(t){
    }

    const string Name;
};


class Dog : public Animal {
public:
    // ваш код

    Dog(string t)
    :Animal(t){
    }

    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};
