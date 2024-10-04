#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <set>
using namespace std;

//


void factor(int a, set<int>& ans) {
	if (a <= 0) {
		return;
	}

	for (int i = 1; i * i <= a; i++) {

		if (i * i == a) {
			ans.insert(i);
		}
		else if (a % i == 0) {
			ans.insert(i);
			ans.insert(a / i);
		}
	}
}

int main() {


	// 약수 중 K번째로 작은 수를 출력
	// 
	set<int> ans;
	int N,K;
	cin >> N>>K;
	factor(N,ans);

	if (ans.size() < K) cout << 0;
	for (auto x : ans)
	{
		K -= 1;
		if (K == 0)
		{
			cout << x;
			break;
		}

	}

}