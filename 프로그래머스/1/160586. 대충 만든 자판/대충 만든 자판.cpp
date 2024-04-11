#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

// 최소문제
// map을 사용해서 문자와 최소개수를 계산한다.


vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char,int> ans;
    
    for(char c= 'A';c<='Z';c++)
        ans[c]=101;
      
    for(auto k : keymap)
    {
        for(int i=0;i<k.size();i++)        
            if(ans[k[i]] > i) ans[k[i]] =i;       
    }
    
    for(auto t : targets)
    {
        int cnt=0;
        for(auto s : t)
        {
            if(ans[s]!=101) cnt+=ans[s]+1;
            else { cnt=-1; break;}
        }

        answer.push_back(cnt);

    }

    return answer;
}