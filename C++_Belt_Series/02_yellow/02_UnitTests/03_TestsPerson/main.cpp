#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
      os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};
/*
class Person {
public:
  // Вы можете вставлять сюда различные реализации класса,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный
  void ChangeFirstName(int year, const string& first_name) {
  }
  void ChangeLastName(int year, const string& last_name) {
  }
  string GetFullName(int year) {
  }
};
*/
void TestIncognito() {
    Person pr;
    AssertEqual(pr.GetFullName(2018), "Incognito");
    pr.ChangeFirstName(2020, "Alina");
    pr.ChangeLastName(2020, "Zhopa");
    AssertEqual(pr.GetFullName(2018), "Incognito");

    pr.ChangeFirstName(2010, "Alina");
    pr.ChangeLastName(2010, "Zadnitza");

    AssertEqual(pr.GetFullName(2007), "Incognito");
}

void TestFullName() {
    Person pr;
    pr.ChangeFirstName(2020, "Alina");
    pr.ChangeLastName(2020, "Zhopa");
    AssertEqual(pr.GetFullName(2020), "Alina Zhopa");

    pr.ChangeFirstName(2010, "Alina");
    pr.ChangeLastName(2010, "Zadnitza");
    AssertEqual(pr.GetFullName(2018), "Alina Zadnitza");
}

void TestOnlyLast() {
    Person pr;
    pr.ChangeLastName(2020, "Zhopa");
    AssertEqual(pr.GetFullName(2020), "Zhopa with unknown first name");

    pr.ChangeLastName(2010, "Zadnitza");
    AssertEqual(pr.GetFullName(2018), "Zadnitza with unknown first name");

    pr.ChangeLastName(2030, "Voniuchka");
    AssertEqual(pr.GetFullName(2030), "Voniuchka with unknown first name");
}

void TestOnlyFirst() {
    Person pr;
    pr.ChangeFirstName(2020, "Zhopa");
    AssertEqual(pr.GetFullName(2020), "Zhopa with unknown last name");

    pr.ChangeFirstName(2010, "Zadnitza");
    AssertEqual(pr.GetFullName(2018), "Zadnitza with unknown last name");

    pr.ChangeFirstName(2030, "Voniuchka");
    AssertEqual(pr.GetFullName(2030), "Voniuchka with unknown last name");
}

void TestSeq() {
    Person pr;
    pr.ChangeFirstName(2010, "Alina");
    AssertEqual(pr.GetFullName(2010), "Alina with unknown last name");

    pr.ChangeLastName(2030, "Voniuchka");
    AssertEqual(pr.GetFullName(2030), "Alina Voniuchka");
    AssertEqual(pr.GetFullName(2010), "Alina with unknown last name");

    pr.ChangeFirstName(2000, "Polina");
    AssertEqual(pr.GetFullName(2000), "Polina with unknown last name");

    pr.ChangeLastName(200, "Malina");
    AssertEqual(pr.GetFullName(200), "Malina with unknown first name");
}

int main() {
  TestRunner runner;
    // добавьте сюда свои тесты
  runner.RunTest(TestIncognito, "TestIncognito");
  runner.RunTest(TestFullName, "TestFullName");
  runner.RunTest(TestOnlyLast, "TestOnlyLast");
  runner.RunTest(TestOnlyFirst, "TestOnlyLast");
  runner.RunTest(TestSeq, "TestSeq");

  return 0;
}
