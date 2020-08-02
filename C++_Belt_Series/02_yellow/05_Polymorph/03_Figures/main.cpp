#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include <cmath>

using namespace std;

class Figure{
public:
    virtual string Name() = 0;
    virtual double Perimeter() = 0;
    virtual double Area() = 0;

private:
    const string name;
};

class Triangle : public Figure{
public:
    Triangle(int a, int b, int c): a(a), b(b), c(c){};
    string Name() override{
        return "TRIANGLE";
    }
    double Area() override{
        double p = (a + b + c);
        p /= 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
    double Perimeter() override{
        return a + b + c;
    }

private:
    const int a;
    const int b;
    const int c;
};

class Circle : public Figure{
public:
    Circle(int r): r(r){}

    string Name() override{
        return "CIRCLE";
    }

    double Area() override{
        return 3.14  * r * r;
    }
    double Perimeter() override{
        return 2 * 3.14 * r;
    }

private:
    int r;
};

class Rect : public Figure{
public:
    Rect(int a, int b): a(a), b(b){}

    string Name() override{
        return "RECT";
    }

    double Area() override{
        return a * b;
    }
    double Perimeter() override{
        return 2 * (a + b);
    }

private:
    int a;
    int b;
};

shared_ptr<Figure> CreateFigure(istringstream& is){
    string type;
    is >> type;
    shared_ptr<Figure> out = make_shared<Circle>(1);
    if (type == "RECT"){
        int a, b;
        is >> a >> b;
        return make_shared<Rect>(a, b);
    } else if (type == "TRIANGLE"){
        int a, b, c;
        is >> a >> b >> c;
        return make_shared<Triangle>(a, b, c);
    }else if (type == "CIRCLE"){
        int r;
        is >> r;
        return make_shared<Circle>(r);
    }
    return out;
}

int main() {
    vector<shared_ptr<Figure>> figures;
    for (string line; getline(cin, line); ) {
        istringstream is(line);

        string command;
        is >> command;
        if (command == "ADD") {
            // Пропускаем "лишние" ведущие пробелы.
            // Подробнее об std::ws можно узнать здесь:
            // https://en.cppreference.com/w/cpp/io/manip/ws
            is >> ws;
            figures.push_back(CreateFigure(is));
        } else if (command == "PRINT") {
            for (const auto& current_figure : figures) {
                cout << fixed << setprecision(3)
                     << current_figure->Name() << " "
                     << current_figure->Perimeter() << " "
                     << current_figure->Area() << endl;
            }
        }
    }
    return 0;
}