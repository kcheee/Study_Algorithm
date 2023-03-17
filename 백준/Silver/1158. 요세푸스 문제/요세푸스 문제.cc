#include <iostream>
#include <vector>
using namespace std;

vector<int> Y;
vector<int> X;

int main() {

	int n, k;
	cin >> n >> k;


	for (int i = 1; i <= n; i++)
	{
		Y.push_back(i);
	}
	int a = k - 1;
	while (Y.size() != 0)
	{
		if (Y.size() - 1 > a) {
			X.push_back(Y[a]);
			Y.erase(Y.begin() + a);
			a += k - 1;
		}
		else if (Y.size() - 1 == a) {
			X.push_back(Y[a]);
			Y.pop_back();
			a = 0;
			a += k - 1;
		}
		else if (Y.size() - 1 < a) {
			int x = a - Y.size();
			a = x;
		}
	}
	for (int i = 0; i < X.size(); i++)
	{
		if (i == 0)
			cout << "<";
		
		cout << X[i];
		if (i < X.size()-1)
			cout << ", ";

		if (i == X.size() - 1)
			cout << ">";
	}

}