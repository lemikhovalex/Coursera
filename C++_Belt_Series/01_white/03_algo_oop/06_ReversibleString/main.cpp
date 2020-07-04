#include <iostream>
#include "string"

using namespace std;

class ReversibleString{
public:
    ReversibleString(){
        str = "";
    }
    ReversibleString(const string init){
        str = init;
    }

    void Reverse(){
        int len = str.size();
        char tmp = 0;
        for(int i = 0; i < len / 2; i ++){
            tmp = str[i];
            str[i] = str[len - 1 - i];
            str[len - 1 - i] = tmp;
        }
    }

    string ToString() const{
        return str;
    }

private:
    string str;

};

int main() {
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;

    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;

    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;

    return 0;
}