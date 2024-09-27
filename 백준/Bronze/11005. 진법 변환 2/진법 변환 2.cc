#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

// 몫과 나머지의 값을 구하고 나머지 값이 출력값이다.


string solution(long long n, int b)
{
	string ans;
	
	while (n!=0)
	{
		if (n % b > 9)
		{			

			ans += (char)(n % b + 'A' - 10);
		}
		else
		{
			ans += n % b + '0';
			
		}
		n /= b;
	}

	reverse(ans.begin(), ans.end());

	return ans;
}

int main() {

	long long N;
	int B;

	
	cin >> N >> B;

	cout<<solution(N,B);

}