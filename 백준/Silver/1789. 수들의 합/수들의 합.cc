#include <iostream>

using namespace std;

int main() {

	long long n = 0;
	long long add = 0;
	int result = 0;
	cin >> n;

	if (n == 1) cout << 1;
	else {

		while (true)
		{
			add += result;

			if (n == add) break;
			else if (n < add) {	result--; break;}
			result++;
		}
		cout << result;
	}

}