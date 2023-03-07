#include <iostream>
using namespace std;

int main() {

	int n;
	cin >> n;

	int tile[1001];
	tile[0] = 0;
	tile[1] = 1;
	tile[2] = 2;
	
	for (int i = 3; i < 1001; i++)
	{
		tile[i] = tile[i - 2] + tile[i - 1]%10007;
	}
	cout << tile[n]%10007;
}