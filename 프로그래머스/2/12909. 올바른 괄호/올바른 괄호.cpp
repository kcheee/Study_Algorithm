#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    
    // 괄호를 열었을 때 a가 +
    // 괄호를 닫았을 때 a가 -
    // a가 음수일때 false;
    // s.length()가 끝까지 가고 a가 0일때 true
    
    int a=0;
    bool answer = false;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(') a++;
        else {
            
            a--;
        }
        if(a<0) return false;
    }
    

    if(a==0) answer =true;

    return answer;
}