#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	int N, input;
	string cmd;
	cin >> N;
	queue <int> q;
	for (int i = 0; i < N; i++) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> input;
			q.push(input);
		}
		else if (cmd == "front") {
			if (q.empty()) cout << -1 << endl;
			else
				cout << q.front() << endl;
		}
		else if (cmd == "back") {
			if (q.empty()) cout << -1 << endl;
			else
			cout << q.back() << endl;
		}
		else if (cmd == "pop") {
			if (q.empty()) cout << -1 << endl;
			else {
				cout << q.front() << endl;
				q.pop();
			}
		}
		else if (cmd == "empty") {
			cout << q.empty() << endl;
		}
		else if (cmd == "size") {
			cout << q.size() << endl;
		}
	}
}