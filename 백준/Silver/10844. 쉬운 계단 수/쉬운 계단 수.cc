#include <iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	long long dp[101][101];

	dp[1][0] = 0; dp[2][0] = 1;
	dp[1][1] = 1; dp[2][1] = 1;
	dp[1][2] = 1; dp[2][2] = 2;
	dp[1][3] = 1; dp[2][3] = 2;
	dp[1][4] = 1; dp[2][4] = 2;
	dp[1][5] = 1; dp[2][5] = 2;
	dp[1][6] = 1; dp[2][6] = 2;
	dp[1][7] = 1; dp[2][7] = 2;
	dp[1][8] = 1; dp[2][8] = 2;
	dp[1][9] = 1; dp[2][9] = 1;

		for (int i = 3; i <= 100; i++)
		{
			dp[i][0] = dp[i - 1][1];
			dp[i][9] = dp[i - 1][8];
			for (int j = 1; j < 9; j++)
			{
				dp[i][j] = (dp[i - 1][j + 1] + dp[i - 1][j - 1]) %1000000000;
			}
		}
		long long sum = 0;
		for (int i = 0; i <= 9; i++) {
			sum += dp[n][i];
		}
		
		sum = sum % 1000000000;
		cout << sum;
		return 0;
}