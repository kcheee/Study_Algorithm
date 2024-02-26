#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int a = 0, b = 0;
    string answer = "";
    bool flag = false;

    for (int i = 0; i < goal.size(); i++)
    {
        if (goal[i] == cards1[a] || goal[i] == cards2[b]) {
            if (goal[i] == cards1[a]) {
                if (cards1.size() > a)
                    a++;
                continue;
            }
            if (goal[i] == cards2[b]) {
                if (cards2.size() >b)
                    b++;
                continue;
            }
        }
        else {
            answer = "No";
            flag = true;
            break;
        }
    }
    if (!flag)
        answer = "Yes";

    return answer;
}