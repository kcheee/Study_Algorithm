#include <iostream>

using namespace std;

int main() {

	int n, m;

	while (1)
	{
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;

		if (m % n == 0) {
			cout << "factor"<<endl;
		}
		else if(n%m==0){
			cout << "multiple" << endl;
		}
		else
			cout << "neither" << endl;

		
	}

}