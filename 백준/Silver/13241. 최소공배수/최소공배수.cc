#include <iostream>
#include <set>
#include <string>

using namespace std;

long long int gcd(long long int a, long long int b)
{
	long long int r;
	while (b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

long long int lcm(long long int a, long long int b) { return (a * b / gcd(a, b)); }

int main() {


	int a, b;
	cin >> a >> b;

	cout << lcm(a, b) << endl;


}



