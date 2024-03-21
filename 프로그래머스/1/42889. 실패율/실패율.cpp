#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

// 실패율 스테이지 도달했으나 클리어 안된 플레이어 수 / 스테이지에 도달한 플레이어 수
// dp를 사용하자
// 실패율 같다면 낮은 스테이지 순서로

bool compare(pair<float,int> a,pair<float,int> b)
{
    if(a.first==b.first) return a.second<b.second;
    return a.first>b.first;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<float,int>> res;
    map<int,int> ans;
    int dp[501];    // 클리어 한 사람들
    for(int i=0;i<stages.size();i++)
        ans[stages[i]]++;
    
    // dp
    dp[N] = ans[N+1];
    for(int i=N-1;i>=0;i--)
        dp[i] = dp[i+1] + ans[i+1];
      
    for(int i=0;i<N;i++)
        res.push_back({(dp[i] == 0) ? 0 : float(ans[i+1]) / float(dp[i]), i + 1});
    
    cout<<endl;
    sort(res.begin(),res.end(),compare);
    for(auto n : res) 
    {
        answer.push_back(n.second);
        cout<<n.first<<":"<<n.second<<" ";
    }

    return answer;
}