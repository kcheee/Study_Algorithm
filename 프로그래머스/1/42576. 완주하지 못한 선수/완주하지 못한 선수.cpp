#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    map<string,int> ans;
    
    for(auto n : participant) ans[n]++;
    
    for(auto n : completion) ans[n]--;
    
    for(auto it = ans.begin();it != ans.end();it++)
    {
        if(it->second==1) answer = it->first;
    }
    return answer;
}