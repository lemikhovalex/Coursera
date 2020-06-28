
#include <iostream>
using namespace std;

int main() {
	double n, a, b , x, y;
	cin >> n >> a >> b >> x >> y;
	double out = n;
	if (n > a && n <= b){
		out -= n * x / 100.0;
	}

	if (n > b){
		out -= n * y / 100.0;
	}
	cout << out;

	return 0;
}
