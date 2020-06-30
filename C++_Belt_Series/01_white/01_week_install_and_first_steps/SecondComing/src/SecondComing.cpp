#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int c = 0;
	for(unsigned int  i = 0; i < s.length(); i++){
		if (s[i] == 'f'){
			c ++;
		}
		if (c==2){
			cout << i;
			return 0;
		}
	}
	if(c == 0){
		cout << -2;
	}
	if (c == 1){
		cout << -1;
	}
	return 0;
}
