#include <iostream>
#include <algorithm>
using namespace std;

int lope[100001] = { 0 };
int main() {

	int n;
	cin >> n;


	for (int i = 0; i < n; i++)
	{
		cin >> lope[i];
	}
	sort(lope, lope + n);
	int j = n;
	int max = 0; 
	int cnt = 1;
	for (int i = n-1; i >= 0; i--)
	{
		if (max < lope[i]*cnt)
			max = lope[i]*cnt;
		cnt++;
	}
	cout << max;
}