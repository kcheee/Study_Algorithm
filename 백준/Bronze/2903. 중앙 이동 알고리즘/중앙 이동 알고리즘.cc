#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

//



int main() {

	int ans[16];
	ans[0] = 2;

	for (int i = 1; i < 16; i++)
	{
		ans[i] = ans[i - 1] * 2 - 1;

	}
	
	int a;
	cin >> a;


	cout << ans[a]*ans[a];

	
}