#include<iostream>
#include<queue>
using namespace std;
queue<int>que;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr); //rapid IO
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		que.push(i);
	}
	while (1) {
		if (que.size() == 1) break;
		que.pop();
		que.push(que.front());
		que.pop();
	}
	cout << que.back() << '\n';
	return 0;
}