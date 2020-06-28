#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double a, b, c;
	cin >> a >> b >> c;
	// a x^2 + b x + c = 0
	if (a == 0 && b == 0){
		return 0;
	}

	if (a == 0 ){
		cout << -1 * c / b;
		return 0;
	}else{
		double d = b * b - 4 * a * c;
		if (d > 0)
		{
			d = sqrt(d);
			cout << (-1 * b + d) / (2 * a) << " " << (-1 * b - d) / (2 * a);
			return 0;
		}
		if (d == 0){
			cout << (-1 * b) / (2 * a);
			return 0;
		}
		if (d < 0){
			return 0;
		}

	}
	return 0;
}
