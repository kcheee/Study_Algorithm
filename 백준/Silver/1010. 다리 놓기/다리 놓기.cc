#include <iostream>	

using namespace std;

int main() {

	// dp문제

	int num, n, m;
	int dp[31][31];
	cin >> num;

	for (int i = 1; i < 31; i++)
	{
		dp[1][i] = i;
	}

	for (int i = 2; i < 31; i++)
	{
		for (int j = 2; j < 31; j++)
		{
			if (i == j) {
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
		}
	}

	for (int i = 0; i < num; i++)
	{
		cin >> n >> m;
		cout << dp[n][m] << "\n";
	}
}