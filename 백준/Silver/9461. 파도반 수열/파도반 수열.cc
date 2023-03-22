#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	long long Dp[101] = { 0 };
	
	Dp[0]=1,Dp[1]=1,Dp[2] = 1;
	Dp[3]=2, Dp[4] = 2;
	Dp[5] = 3;
	Dp[6] = 4;
	Dp[7] = 5;

	for (int i = 7; i < 101; i++)
	{
		Dp[i] = Dp[i - 1] + Dp[i - 5];
	}
	int a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		cout << Dp[a - 1] << endl;
	}
}