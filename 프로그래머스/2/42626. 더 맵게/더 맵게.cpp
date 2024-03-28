#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

// 가장 첫번째와 두번째가 둘다 0일 경우 -1 리턴
int solution(vector<int> scoville, int K) {
    int answer = 0;
    multiset<int> ans;
    
    for(auto n : scoville) 
    {
        ans.insert(n);
    }
    // auto it = ans.begin();
    if(*(++ans.begin()) ==0) return -1;
    while(*ans.begin()<K&&ans.size()>1)
    {
        int cnt = *ans.begin()+ *(++ans.begin()) *2;
        ans.erase(ans.begin(),next(ans.begin(), 2));     
        ans.insert(cnt);
        answer++;
    }
    if(ans.size()==1 && *ans.begin()<K) return -1; 
    for(auto n : ans) cout <<n;
    
    return answer;
}