#include <iostream>

using namespace std;

int main() {

	int n;
	cin >> n;
	int q = 1;
	int z = n * 2 - 1;
	for (int i = 1; i < n*2; i++)
	{
		
		for (int j = i; j <=n-1 ; j++)
		{
			cout << " ";
		}
		for (int k = 0; k < q&&q<n*2; k++)
		{
			cout << "*";	
		}
		if (i > n) {

			z -= 2;
			for (int w = 0; w < i - n; w++)
			{
				cout << " ";
			}
			for (int y = z; y >0; y--)
			{
				cout << "*";
			}

		}
		if (q < (n * 2))
			q += 2;
		cout << endl;
	}
	
}