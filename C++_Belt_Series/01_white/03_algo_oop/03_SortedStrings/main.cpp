#include <iostream>
#include "string"
#include "vector"
#include "algorithm"

using namespace std;

class SortedStrings {
public:
    void AddString(const string& s) {
        vec_of_strings.push_back(s);
    }
    vector<string> GetSortedStrings() {
        sort(begin(vec_of_strings), end(vec_of_strings));
        return vec_of_strings;
    }
private:
    vector<string> vec_of_strings;
};
/*
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
*/