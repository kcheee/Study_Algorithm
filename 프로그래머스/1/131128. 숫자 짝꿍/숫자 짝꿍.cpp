#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

// 존재하지 않으면 -1 0으로 구성되어있으면 0


string solution(string X, string Y) {
    string answer = "";
    
    map<char,int> mx;
    map<char,int> my;
    
    for(auto c : X) mx[c]++; 
    for(auto c : Y) my[c]++;
      
    for(int i=9;i>=0;i--)
    {
        char c = i+'0';
        while(mx[c] !=0&&my[c] !=0) 
        {
            answer+=c;
            mx[c]--;
            my[c]--;
        }
    }
    
    if(answer=="") return "-1";
    else if (answer[0]=='0') return "0";
    return answer;
}