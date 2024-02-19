#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    
    // 가장 처음에 나온 숫자는 -1
    // s[i]-97 =0 ~ 25
    // a배열에 인덱스 위치를 기억한다.
    
    int a[26];
    for(int i = 0; i < 26; i++) a[i] = -1;
    
    vector<int> answer;
    
    cout<<a[2];
    a[s[0]-97] =0;
    answer.push_back(-1);
       
    for(int i=1;i<s.size();i++)
    {
        // 처음 나왔으면
        if(a[s[i]-97]==-1) 
        {
            answer.push_back(-1);
            a[s[i]-97] = i;         
        }
        // 아니라면
        else
        {
            answer.push_back(i-(a[s[i]-97]));           
            a[s[i]-97] = i;
        }
    }    
    return answer;
}