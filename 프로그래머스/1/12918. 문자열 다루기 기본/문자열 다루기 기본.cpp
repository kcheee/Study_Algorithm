#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool solution(string s) {
    bool answer = true;
    
    if(s.length()!=4 && 6!=s.length())
        return 0;
    
    for(int i=0;i<s.length();i++)    
        if(s[i]<47 || 58<s[i]) return 0;
    
    
    return answer;
}