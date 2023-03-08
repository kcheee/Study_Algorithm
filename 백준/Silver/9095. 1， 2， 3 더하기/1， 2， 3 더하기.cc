#include <iostream>

using namespace std;

int cnt = 0;
void num_sum(int n) {

	if (n == 0) {
		cnt++;
	}
	for (int i = 1; i <= 3; i++)
	{
		if ((n - i) >= 0)
			num_sum(n - i);
	}
}

int main() {

	int n;
	cin >> n;
	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		num_sum(num);
		cout << cnt << endl;
		cnt = 0;
	}

}