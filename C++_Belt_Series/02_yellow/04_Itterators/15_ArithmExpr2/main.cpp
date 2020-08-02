#include <iostream>
#include <deque>

using namespace std;

void upd_ar_expr(deque <string> & expr, string x, char act, char prev_act){

    if (act == 0){
        expr.push_back(x);
    }else if (act == '*' || act == '/'){
        if (prev_act == '+' || prev_act == '-'){
            expr.push_front("(");
            expr.push_back(")");
        }
        expr.push_back(" " + string(1, act) + " " + x);
    } else{
        expr.push_back(" " + string(1, act) + " " + x);
    }
}

void print_deque(const deque <string> & expr){
    for(auto e : expr){
        cout << e;
    }
}

int main() {
    int n;
    string x;
    cin >> x;
    cin >> n;
    char act = 0;
    deque <string> out;
    upd_ar_expr(out, x, act, 0);
    char prev_act = 0;
    for(int i = 0; i < n; ++ i){
        cin >> act >> x;
        upd_ar_expr(out, x, act, prev_act);
        prev_act = act;
    }
    print_deque(out);

    return 0;
}
