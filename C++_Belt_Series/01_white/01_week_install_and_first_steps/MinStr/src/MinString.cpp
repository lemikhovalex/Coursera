#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string a ,b, c;
	cin >> a >> b >> c;
	vector<string> vec = {a, b, c};
	string minn = vec[0];
	for (auto s : vec){
		if (minn > s){
			minn = s;
		}
	}
	cout << minn;
	return 0;
}
