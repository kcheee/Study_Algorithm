#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

// 1부터 n까지
int solution(vector<int> order) {
    int answer = 0;
    stack<int> ans;
    int a=0;
    for(int i=1;i<order.size()+1;i++)
    {
        if(i!=order[a])
            ans.push(i);
        
        else
        {
            ans.push(i);
            while(!ans.empty() &&  ans.top() == order[a])
            {
                answer++;
                ans.pop();
                a++;
            }
        }
    }
    return answer;
}