#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int num=0;
bool compare(pair<int,string> a, pair<int,string> b)
{
    if(a.second[num]==b.second[num]) return a.second < b.second; 
    
    return a.second[num]<b.second[num];
}
vector<string> solution(vector<string> strings, int n) {
    
    // 오름차순 greater<int>()
    // n번째의 값 비교
    // 값이 같으면 사전순
    
    num=n;
    vector<string> answer;
    vector<pair<int,string>> ans;
    for(int i=0;i<strings.size();i++)
    {      
        ans.push_back({i,strings[i]});
    }
    sort(ans.begin(),ans.end(),compare);
    for(int i=0;i<strings.size();i++)
    {
        answer.push_back(ans[i].second);
    }
    
    return answer;
}