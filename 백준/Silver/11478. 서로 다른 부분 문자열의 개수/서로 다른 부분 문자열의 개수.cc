#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
	
	string S;
	cin >> S;


	set<string> set_cnt;
	int s_cnt = 1;
	while (true)
	{
		int n=0;
		while (n+s_cnt!=S.size()+1)
		{
			set_cnt.insert(S.substr(n, s_cnt));
			n++;		
		}
		if (s_cnt == S.size()) break;
		s_cnt++;
	}

	cout << set_cnt.size();
}
