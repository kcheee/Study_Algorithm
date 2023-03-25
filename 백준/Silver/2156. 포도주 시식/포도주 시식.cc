#include<iostream>
#include<algorithm>
using namespace std;

int s[10002]; 
int dp[10002];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; 
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}

	dp[0] = 0; //쓰이지않는인덱스와값
	dp[1] = s[1];
	dp[2] = s[1] + s[2];
	dp[3] = max(max(s[1] + s[2], s[2] + s[3]),s[1]+s[3]);
	for (int i = 4; i <= n; i++) {
		dp[i] = max(max(dp[i - 1], dp[i - 2] + s[i]), dp[i - 3] + s[i - 1] + s[i]);
	}

	// 반례
	// 6 1000 1000 1 1 1000 1000 (두 잔 연속 안 마시는 경우)	4000
	

	cout << dp[n];

	return 0;
}