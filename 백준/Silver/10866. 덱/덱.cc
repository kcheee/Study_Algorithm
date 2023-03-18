#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {

	int N, input;
	string cmd;
	cin >> N;
	deque <int> q;
	for (int i = 0; i < N; i++) {
		cin >> cmd;
		if (cmd == "push_front") {
			cin >> input;
			q.push_front(input);
		}
		else if (cmd == "push_back")
		{
			cin >> input;
			q.push_back(input);
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
		else if (cmd == "pop_front") {
			if (q.empty()) cout << -1 << endl;
			else {
				cout << q.front() << endl;
				q.pop_front();
			}
		}
		else if (cmd == "pop_back") {
			if (q.empty()) cout << -1 << endl;
			else {
				cout << q.back() << endl;
				q.pop_back();
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