#include <iostream>
using namespace std;
 
int A = 0;
int B = 0;
int C = 0;
 
int main() {
	cin >> A >> B >> C;
 
	if (A <= B && C <= A || B <= A && A <= C) {
		cout << A << endl;
	}
	else if (B <= A && C <= B || B <= C && A <= B) {
		cout << B << endl;
	}
	else {
		cout << C << endl;
	}
}