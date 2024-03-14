#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

// 사과의 최대 점수 k
// 한 상자에 담기는 사과 개수 m
// 이익이 발생하지 않는 경우 0

int solution(int k, int m, vector<int> score) {
    
    int answer = 0;
    vector<int> ans;
    map<vector<int>,int> res;
    
    if(m>score.size()) return 0;
    
    sort(score.begin(),score.end(),greater<>());
    
    for(int i=0;i<score.size();i++)
    {
        ans.push_back(score[i]);
        if(i!=0&&(i+1)%m==0)
        {
            res[ans]++;
            ans.clear();
        }
    }
    for (auto it = res.begin(); it != res.end(); ++it)         
        answer+= it->first[m-1]*m*(it->second);        
    
    
    return answer;
}