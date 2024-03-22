#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <map>
using namespace std;

// 두개의 값이 들어갈 수도 있으니 map을 사용해야 하나

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> que_;
    map<int,int> ans;
    
    for(auto n : operations )
    {
        // 삽입
        if(n[0] == 'I')
        {
            int num = stoi(n.substr(2,n.size()-2));            
            ans[num]++;           
        }
        else if(n[0]=='D')
        {
            string str = n.substr(2,n.size()-2);
            if(str=="1") 
            {     
                if(!ans.empty())
                {    
                    if(prev(ans.end())->second>1)
                        prev(ans.end())->second--;
                    else
                        ans.erase(prev(ans.end()));
                }
            }
            else if(str=="-1")
            {
                if(!ans.empty())
                {                 
                    if(ans.begin()->second>1)
                        ans.begin()->second--;
                    else
                        ans.erase(ans.begin());
                }
            }
        }
    }
    if(ans.empty()) 
    {
        answer.push_back(0);
        answer.push_back(0);
        return answer;
    }
    answer.push_back(prev(ans.end())->first);
    answer.push_back(ans.begin()->first);
        
    for(auto n : ans) cout<<n.first;
    return answer;
}