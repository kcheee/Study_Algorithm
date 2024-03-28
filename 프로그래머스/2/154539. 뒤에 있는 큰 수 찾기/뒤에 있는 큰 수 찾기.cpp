#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

vector<int> solution(vector<int> numbers) {
    
    vector<int> answer(numbers.size(),-1);
    stack<pair<int,int>> a;
       
    // -1이 나오는 곳은
    for(int i=0;i<numbers.size()-1;i++)
    {
        a.push({numbers[i],i});
        while(1)
        {
            if(!a.empty()&&a.top().first<numbers[i+1])
            {
                answer[a.top().second] = numbers[i+1];
                a.pop();
                continue;
            }
            else break;
        }
    }
    
    return answer;
}