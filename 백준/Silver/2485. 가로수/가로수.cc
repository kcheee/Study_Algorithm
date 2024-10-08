#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 최소 숫자 이므로 각 간격의 차이값을 구함
//

int gcd(int a, int b)
{
	int r;
	while (b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {

	int N;
	cin >> N;
	vector<int> vec;
	set<int> set;

	int ans = 0;
	// 각 차이값을 구함.
	// 차이값 중 가장 큰값과 가장 작은 값을 gcd
	for (int i = 0; i < N; i++)
	{
		int a; cin >> a;

		vec.push_back(a);
		if (i == 0)continue;
		set.insert(vec[i] - vec[i - 1]);

	}
	
	auto it = set.begin();
	int G = *it;
	++it;
	for (; it != set.end(); ++it) {
		G = gcd(G, *it);
	}

	for (int i = 1; i < vec.size(); i++)
	{
		ans += (vec[i] - vec[i - 1]) / G - 1;
	}

	cout << ans;
}



