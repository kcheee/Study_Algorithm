#include <iostream>
#include <string>

using namespace std;


int main() {

	int n;
	cin >> n;
	string num;
	
	int po = 23;
	// 1. 짝수 홀수인지 체크
	// 짝수 => 반을 나눠 + 계산
	// 홀수 => 반을 나누고 맨 왼쪽에 있는 숫자와 가장 가운데에 있는 숫자 비교해서 계산

for (int i = 0; i < n; i++)
	{
		cin >> num;

		if (num.length() % 2 == 0)
		{
			int flag = num.length() / 2;
			int a = stoi(num.substr(0, flag));
			int b = stoi(num.substr(flag, num.length()));
			cout << "#" << i + 1 << " " << a+b << "\n";
		}
		else {
			int flag = num.length() / 2;
			int a = stoi(num.substr(0, 1));
			int b = stoi(num.substr(flag, 1));
			if (a > b) {
				int result_a = stoi(num.substr(0, flag));
				int result_b = stoi(num.substr(flag, num.length()));
				cout <<"#"<<i+1<<" "<< result_a + result_b << "\n";
			}
			else if (a == b) {
				int a = stoi(num.substr(0, flag));
				int b = stoi(num.substr(flag+1, num.length()));
				if (a > b) {
					int result_a = a;
					int result_b = stoi(num.substr(flag, num.length()));
					cout << "#" << i + 1 << " " << result_a + result_b << "\n";
				}
				else {
					int result_a =stoi(num.substr(0, flag+1));
					int result_b = b;
					cout << "#" << i + 1 << " " << result_a + result_b << "\n";
				}
			}
			else
			{
				int result_a = stoi(num.substr(0, flag+1));
				int result_b = stoi(num.substr(flag+1, num.length()));
				cout << "#" << i + 1 << " " << result_a + result_b << "\n";
			}

		}
	}
return 0;
}