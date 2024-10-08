#include <iostream>
#include <set>
#include <string>

using namespace std;

int gcd(int a, int b)
{
	int r;
	while (b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b) { return (a * b / gcd(a, b)); }

int main() {

	int T;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int a, b;
		cin >> a >> b;
		
		cout << lcm(a, b)<<endl;

	}

}
