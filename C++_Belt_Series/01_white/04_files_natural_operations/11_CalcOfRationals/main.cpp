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
        if (denominator == 0){

            // stringstream ss;
            // ss <<"";
            // throw runtime_error(ss.str());
            throw invalid_argument("Invalid argument");
        }
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
    if (rhs.Numerator() == 0){
        throw domain_error("Division by zero");
    }

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
        return lhs.Numerator() * rhs.Denominator() < rhs.Numerator() * lhs.Denominator();
    } else if (lhs.Sign() < 0){
        return lhs.Numerator() * rhs.Denominator() > rhs.Numerator() * lhs.Denominator();

    }
    return false;
}



int main() {
    Rational a, b;
    string oper;
    Rational out;
    try {
        cin >> a >> oper >> b;
        if (oper == "+"){
            out = a + b;
        } else if( oper == "-"){
            out = a - b;
        } else if(oper == "/"){
            out = a / b;
        } else if(oper == "*"){
            out = a * b;
        }
        cout << out;
    }catch (exception& ex) {
        cout << ex.what();
    }
    return 0;
}
