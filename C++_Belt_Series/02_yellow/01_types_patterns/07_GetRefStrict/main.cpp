#include <iostream>
#include "vector"
#include "map"

using namespace std;

template <typename First, typename Second>
Second& GetRefStrict(map<First, Second>& m, const First key){
    map<First, Second> out;
    if (m.count(key) == 0){
        throw runtime_error("No value for key in GetRefStrict");
    }
    return m[key];
};

using namespace std;
int main() {
    map<int, string> m = {{0, "value"}};
    string& item = GetRefStrict(m, 0);
    item = "newvalue";
    cout << m[0] << endl; // выведет newvalue
}
