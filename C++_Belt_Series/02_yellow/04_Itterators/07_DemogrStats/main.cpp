#include <iostream>
#include "vector"
#include "algorithm"

using namespace  std;
template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end);
/*
enum class Gender {
    FEMALE,
    MALE
};

struct Person {
    int age;  // возраст
    Gender gender;  // пол
    bool is_employed;  // имеет ли работу
};
*/
void PrintStats(vector<Person> persons){
    cout << "Median age = " << ComputeMedianAge(persons.begin(), persons.end()) << endl;
    //females
    auto fem__male = partition(persons.begin(), persons.end(), [](Person p){return p.gender == Gender::FEMALE;});
    cout << "Median age for females = " << ComputeMedianAge(persons.begin(), fem__male) << endl;
    //male
    cout << "Median age for males = " << ComputeMedianAge(fem__male, persons.end()) << endl;
    // empl fem
    auto emp_fem__unemp_fem = partition(persons.begin(), fem__male, [](Person p){return p.is_employed == true;});
    cout << "Median age for employed females = " << ComputeMedianAge(persons.begin(), emp_fem__unemp_fem) << endl;
    // un emp fem
    cout << "Median age for unemployed females = " << ComputeMedianAge(emp_fem__unemp_fem, fem__male) << endl;
    // empl males
    auto emp_mal__unemp_mal = partition(fem__male, persons.end(), [](Person p){return p.is_employed == true;});
    cout << "Median age for employed males = " << ComputeMedianAge(fem__male, emp_mal__unemp_mal) << endl;
    // un emp males
    cout << "Median age for unemployed males = " << ComputeMedianAge(emp_mal__unemp_mal, persons.end()) << endl;
}
/*
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
*/