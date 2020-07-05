#include <iostream>
#include <sstream>
#include "set"
#include "vector"
#include "map"

using namespace std;

class Rational {
public:
    Rational(){
        p = 0;
        q = 1;
    }

    Rational(int numerator, int denominator){
        // dealing with
        int frac_sign = sign(numerator) * sign(denominator);
        int d = gcd(abs(numerator), abs(denominator));
        p = abs(numerator) / d * frac_sign;
        q = abs(denominator) / d;
    }

    int Numerator() const{
        return p;
    }

    int Denominator() const{
        return q;
    }

    int Sign() const {
        return sign(this->Denominator()) * sign(this->Numerator());
    }

private:
    int p;
    int q;

    int gcd(int a, int b){
        while (a > 0  && b > 0){
            if (a > b){
                a = a % b;
            }else{
                b = b % a;
            }
        }
        return a + b;
    }

    int sign(int a) const {
        if (a > 0){
            return 1;
        } else if (a < 0){
            return -1;
        }
        return  0;
    }
};

Rational operator+(const Rational& lhs, const Rational& rhs){
    int loc_p = lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator();
    int loc_q = rhs.Denominator() * lhs.Denominator();
    return {loc_p, loc_q};
}

Rational operator-(const Rational& lhs, const Rational& rhs){
    int loc_p = lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator();
    int loc_q = rhs.Denominator() * lhs.Denominator();
    return {loc_p, loc_q};
}

bool operator==(const Rational& lhs, const Rational& rhs){
    return (lhs.Numerator() * rhs.Denominator() == rhs.Numerator() * lhs.Denominator() );
}

Rational operator*(const Rational& lhs, const Rational& rhs){
    int loc_p = lhs.Numerator() * rhs.Numerator();
    int loc_q = rhs.Denominator() * lhs.Denominator();
    return {loc_p, loc_q};
}

Rational operator/(const Rational& lhs, const Rational& rhs){
    Rational loc_r = Rational(rhs.Denominator(), rhs.Numerator());
    return lhs * loc_r;
}

istream& operator>>(istream& stream, Rational& r){
    int p_loc;
    int q_loc;
    if(stream >> p_loc){
        stream.ignore(1);
        stream >> q_loc;
        r = Rational(p_loc, q_loc);
    }

    return stream;
}

ostream& operator<<(ostream& stream, const Rational r) {
    stream << r.Numerator() << "/" << r.Denominator();
    return stream;
}

bool operator<(const Rational & lhs, const Rational & rhs){
    if (lhs.Sign() < rhs.Sign()){
        return true;
    } else if(lhs.Sign() > rhs.Sign()){
        return false;
    }

    if (lhs.Sign() > 0){
        if(lhs.Numerator() * rhs.Denominator() < rhs.Numerator() * lhs.Denominator()){
            return true;
        } else{
            return false;
        }
    } else if (lhs.Sign() < 0){
        if(lhs.Numerator() * rhs.Denominator() > rhs.Numerator() * lhs.Denominator()){
            return true;
        } else{
            return false;
        }

    }
    return false;
}




int main() {

    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "OK1" << endl;

    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK2" << endl;

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK3" << endl;

     {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK4" << endl;

    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }
    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK5" << endl;
    return 0;
}
