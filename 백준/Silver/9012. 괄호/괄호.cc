#include <iostream>
#include <vector>
using namespace std;

int main()
{
	string str;
	vector<string> answer;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> str;
		int a = 0, b = a + 1;
		while (true)
		{
			if (str[a] == '(')
			{
				if (str[b] == ')')
				{
					str.erase(str.begin() + a);
					str.erase(str.begin() + b-1);
					a = 0;
					b = 0;
				}
				b++;
				if (str == "\0") {
			
					answer.push_back("YES");
					break;
				}
				if (str.length() < b) {
				
					answer.push_back("NO");
					break;
				}

			}
			if (str[a] != '(') {
				a++;
				if (str.length() <= a) {
					answer.push_back("NO");
					break;
				}
			}
		}
		str.clear();
	}
	
	for (int i = 0; i < n; i++)
	{
		cout <<answer[i] << endl;
	}

}
