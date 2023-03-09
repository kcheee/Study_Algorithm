#include <iostream>
using namespace std;
int A[1002];
int dp[1002];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	int max_length = 1;
	for (int i = 1; i <= N; i++)
	{
		dp[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (A[i] > A[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}

		if (dp[i] > max_length) {
			max_length = dp[i];
		}
	}
cout << max_length;
return 0;
}