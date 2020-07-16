//
// Created by lemikhovalex on 16.07.2020.
//
#include <iostream>
#include "phone_number.h"
#include <sstream>

using namespace std;

void get_and_check_sep(stringstream& stream, char sep){
    char plus;
    if(stream >> plus){
        if (plus != sep){
            throw invalid_argument("not sep");
        }
    } else {
        throw invalid_argument("cant get separator");
    }
}

void get_int(stringstream& stream, int& targ){
    if(stream >> targ){
    } else {
        throw invalid_argument("cant read piece of number");
    }
}

PhoneNumber:: PhoneNumber(const string &international_number){
    stringstream stream(international_number);
    int countyr_c, city_c, local_n, tot_loc_n;
    tot_loc_n  = 0;
    // got first +
    get_and_check_sep(stream, '+');
    // getting country code
    get_int(stream, countyr_c);
    // getting minus
    get_and_check_sep(stream, '-');
    // getitng city number
    get_int(stream, city_c);
    //gettitng another minus
    get_and_check_sep(stream, '-');
    stream >> local_number_;
    country_code_ = to_string(countyr_c);
    city_code_ = to_string(city_c);
}

string PhoneNumber::GetCountryCode() const{
    return country_code_;
}

string PhoneNumber::GetCityCode() const{
    return city_code_;
}

string PhoneNumber::GetLocalNumber() const{
    return local_number_;
}

string PhoneNumber::GetInternationalNumber() const{
    return '+' + country_code_ + '-' + city_code_ + '-' + local_number_;
}

/*
int main() {
    PhoneNumber pn("+7-977-111-22-33");
    std::cout << pn.GetInternationalNumber() << std::endl;
    std::cout << pn.GetCountryCode() << std::endl;
    std::cout << pn.GetCityCode() << std::endl;
    std::cout << pn.GetLocalNumber() << std::endl;
    return 0;
}
*/