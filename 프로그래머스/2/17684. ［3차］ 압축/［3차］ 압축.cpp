#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string,int> ans;
    int cnt = 27;
    
    for(int i=65;i<=90;i++)
    {    
        string a;   a+='A'+i-65;  ans[a] = i-64;
    }
    
    for(int i=0;i<msg.size();i++)
    {
        string a;
        a+= msg[i];
        int k=1;
        int j=i;
        // 다음 글자가 사전에 있다면
        while(ans.find(a)!=ans.end())
        {
            string b =a;
            a+= msg[j+k];
            if(ans.find(a)!=ans.end())
            {
                i++;
                k++;
            }
            else
            {
                // 사전에 추가
                answer.push_back(ans[b]);
                cout<<ans[b]<<" ";
                         
                ans[a] = cnt++;
                break;
            }
        }

    }
    
    return answer;
}