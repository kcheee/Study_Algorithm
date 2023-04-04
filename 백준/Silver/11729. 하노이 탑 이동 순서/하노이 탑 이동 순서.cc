#include <iostream>
#include <cmath>
using namespace std;

void Hanoi(int N, int A, int B, int C)
{
	if (N == 1)
		cout << A << " " << C << '\n';
	else
	{
		Hanoi(N - 1, A, C, B);
		cout << A << " " << C << '\n';
		Hanoi(N - 1, B, A, C);
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	int k = (int)pow(2, N) - 1;
	cout << k << '\n';
	Hanoi(N, 1, 2, 3);

	return 0;
}
