#include <iostream>
#include "map"
#include "vector"

using namespace std;

enum class Lang {
    DE, FR, IT
};

struct Region {
    string std_name;
    string parent_std_name;
    map<Lang, string> names;
    int64_t population;
};

bool operator<(map<Lang, string>& lhs, map<Lang, string>& rhs){
    Lang l;
    if()
}

bool operator<(Region& lhs, Region& rhs){
    auto lhs_key = tie(lhs.std_name , lhs.parent_std_name , lhs.names, lhs.population); // сохраним левую дату
    auto rhs_key = tie(rhs.std_name , rhs.parent_std_name , rhs.names, rhs.population); // и правую
    return lhs_key < rhs_key;
}

int FindMaxRepetitionCount(const vector<Region>& regions){

}

int main() {
    return 0;
}
