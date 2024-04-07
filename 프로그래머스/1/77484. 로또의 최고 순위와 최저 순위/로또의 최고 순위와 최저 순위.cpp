#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

// 최저 순위는 5등 까지(2개는 무조건 맞춰야함)
// map을 사용해서 key : int value bool
// 0은 알아볼수 없는 숫자
// 0의 개수를 세고, 만약 0이 없다면 최고순위와 같다
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    map<int,bool> ans;
    int cnt=0;
    int zero_cnt =0;
    for(auto n : win_nums) 
    {
        ans[n] = true;
    }
    for(auto n : lottos) {
        // 최고순위
        if(ans[n]==true) cnt++;
        if(n==0) zero_cnt++;
            
        // 최저순위
    }
    
    for(auto it : ans) {
        if(it.second==true) {
            
        }
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