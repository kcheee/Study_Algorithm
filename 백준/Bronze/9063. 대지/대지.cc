#include <iostream>
#include <vector>
#include <set>
using namespace std;


int main() {

	set<int> sx;
	set<int> sy;

	int x, y;
	int N;
	cin >> N;
	

	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;

		sx.insert(x);
		sy.insert(y);

	}
	if (N == 1 && 
		(*--sx.end() - *sx.begin()) ==0 &&
		(*--sy.end() - *sy.begin())		) 
	{ cout << 0; return 0; }
	
	cout << (*--sx.end() - *sx.begin()) * (*--sy.end() - *sy.begin());
}
