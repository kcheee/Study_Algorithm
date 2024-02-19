#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    if(s.size()%2==1) return 0;
    stack<char> a;
    a.push(s[0]);
    for(int i=1;i<s.size();i++)
    {
        if(!a.empty() && a.top()==s[i]) a.pop();
        else a.push(s[i]);
    }
    
    if(a.empty()) return 1;
    return 0;
}