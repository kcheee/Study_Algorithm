#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
	
	int n, m;

	cin >> n >> m;

	set<int> A;
	set<int> B;

	int cnt_A=0, cnt_B=0;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		A.insert(a);
	}

	for (int i = 0; i < m; i++)
	{
		int b;
		cin >> b;
		if (A.find(b)!=A.end()) cnt_A++;
		B.insert(b);
	}
	
	for (auto a : A)
		if (B.find(a) != B.end()) cnt_B++;
	
	cout << n - cnt_A + m - cnt_B;
}
