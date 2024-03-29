#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
words에 target단어가 없으면 실행 안함.
dfs 방법 사용
1. 단어중 알파벳 한글자만 다른 단어를 찾아야 함.
2. target과 알파벳 하나만 다르다면 답은 그것이다
*/
bool str_bool(string a,string b)
{
    int cnt=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=b[i]) cnt++;
        if(cnt>1) return false;
    }
    return true;
}
bool flag[51];
vector<string> str;
int answer = 55; 
void dfs(string s,string target,int ans)
{
    // target을 찾은경우

    if(str_bool(s,target)) 
    {
        ans++;
        answer = answer>ans ? ans : answer;        
    }
    for(int i=0;i<str.size();i++)
    {
        if(str_bool(s,str[i])&&flag[i]==false)
        {
            flag[i] = true;
           // cout<<str[i]<<" "<<ans<<" ";
            if(str_bool(s,target)) dfs(s,target,++ans);     
            else  dfs(str[i],target,++ans);            
        }
    }
}
int solution(string begin, string target, vector<string> words) {
    
    if(find(words.begin(),words.end(),target) == words.end()) return 0;
    
    str = words;
    
    dfs(begin,target,0);
      
    return answer;
}