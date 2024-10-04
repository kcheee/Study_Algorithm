#include <iostream>
#include <vector>
#include <set>
using namespace std;


int main() {

	set<int> X;
	set<int> Y;

	int ans_x, ans_y;
	for (int i = 0; i < 3; i++)
	{
		int x, y;
		cin >> x >> y;
		
		if (X.find(x) != X.end())
		{
			X.erase(x);
		}
		else
		X.insert(x);

		if (Y.find(y) != Y.end())
		{
			Y.erase(y);
		}
		else
		Y.insert(y);

	}

	cout << *X.begin() << " " << *Y.begin();
}
