#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int arr[100001];
vector<int>	Dp;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> Dp;
	int n;
	cin >> n;
	int sum = 0;
	int m_max = -1001;
	bool flag = false;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] > 0&&!flag) {
			flag = true;
			sum = 0;
		}
		else if(!flag)
		{
			if (m_max < arr[i])
				m_max = arr[i];
		}
		if (flag) {
			if (arr[i] > 0)
				sum += arr[i];
			else if (arr[i] <= 0) {
				Dp.push_back(sum);

				sum += arr[i];
				if (sum < 0)
					sum = 0;
			}
			if (i == n - 1)
				Dp.push_back(sum);
		}
	}

	if (flag)
	{
		sort(Dp.begin(), Dp.end(),greater<int>());
		cout << Dp[0];
	}
	else
		cout << m_max;

}