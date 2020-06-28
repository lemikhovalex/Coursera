#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> reverse;
	if (n == 0)
	{
		reverse = {0};
	}
	while (n > 0)
	{
		reverse.push_back(n % 2);
		n /= 2;
	}
	for (int i = reverse.size() - 1; i >= 0; i-=1){
		//cout << "i=" << i << endl;
		cout << reverse[i];
	}
	// cout << endl << "HH";
	return 0;
}
