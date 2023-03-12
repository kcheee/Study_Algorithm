#include <iostream>
#include <vector>

using namespace std;

int main() {

	int k;
	cin >> k;
	vector<int> N;
	int a;
	for (int i = 0; i < k; i++)
	{
		cin >> a;
		if (a == 0)
			N.pop_back();
		else
			N.push_back(a);
	}
	int sum = 0;
	for (int i = 0; i < N.size(); i++)
	{
		sum += N[i];
	}
	cout << sum;
}