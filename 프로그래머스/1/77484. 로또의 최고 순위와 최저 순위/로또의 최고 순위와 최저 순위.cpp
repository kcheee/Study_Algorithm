#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    map<int,bool> ans;
    int cnt=0;
    int zero_cnt =0;
    for(auto n : win_nums) 
        ans[n] = true;
    
    for(auto n : lottos) {
        // 최고순위
        if(ans[n]==true) cnt++;
        if(n==0) zero_cnt++;
    }    
    if(cnt!=0)
    {
        answer.push_back(7-(cnt+zero_cnt));        
        answer.push_back(7-cnt);   
    }
    else
    {
         //맞춘게 없다면
         if(zero_cnt>1) answer.push_back(7-zero_cnt);
             else answer.push_back(6);
         answer.push_back(6);        
    }
    
    return answer;
}