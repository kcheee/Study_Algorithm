#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;


int main() {

	int q=0;
	int d=0;
	int n=0;
	int p=0;

	int m;

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> m;

		if (m / 25 > 0)
		{
			q = m / 25;
			m %= 25;
		}
		if (m / 10 > 0)
		{
			d = m / 10;
			m %= 10;
		}
		if (m / 5 > 0)
		{
			n = m / 5;
			m %= 5;
		}
		if (m / 1 > 0)
		{
			p = m / 1;
			m %= 1;
		}
		cout << q <<" " << d << " " << n << " " << p << endl;
		q = 0, d = 0, n = 0, p = 0;
	}

}