#include <iostream>
#include <algorithm>

using namespace std;

bool desc(int a, int b) {
	return a > b;
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int arr[502];
	int ans[502];
	int tmp;
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> tmp;			
			if (n == 1) {
				cout << tmp;
				return 0;
			}
			if (i == 1)
			{
				arr[j] = tmp;
				ans[j] = tmp;
				continue;
			}
			if (j == 1) {
				arr[j] = ans[j] + tmp;
			}
			else if (j == i) {
				arr[j] = ans[j - 1] + tmp;
			}
			else {
				arr[j] = max(ans[j - 1], ans[j]) + tmp;
			}			
		}
		for (int k = 1; k <=i; k++)
		{
			ans[k] = arr[k];
		}
	}
	sort(ans + 1, ans + n + 1,desc);

	cout << ans[1];
}