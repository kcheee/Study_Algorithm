#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	//1번 집의 색은 2번집의 색과 같지 않아야함
	// n번 집의 색은 n-1번 집의 색과 같지 않아야함
	// i-1번 i+1번 집의 색과 같이 않아야함
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int rgb[1001][3];
	int result[1001][3] = { 0, };

	int n;
	cin >> n;
	int i;
	for (i = 0; i < n; i++)
	{
		cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
	}

	for (i = 0; i < n; i++)
	{
			result[i+1][0] = min(result[i][1], result[i][2]) + rgb[i][0];
			result[i+1][1] = min(result[i][0], result[i][2]) + rgb[i][1];
			result[i+1][2] = min(result[i][0], result[i][1]) + rgb[i][2];	

	}

	cout << min(min(result[n][0], result[n][1]), result[n][2]);

}