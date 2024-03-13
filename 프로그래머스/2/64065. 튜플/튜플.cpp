#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
using namespace std;

bool compare(string a,string b){  return a.size()<b.size();  }

vector<int> solution(string s) {
    vector<int> answer;
    vector<string> ans;
    string str;
    bool flag=false;
    // 처음과 끝에 있는 중괄호 삭제
    s.erase(s.begin());    s.pop_back();
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='}') 
        {
            flag =false;
            ans.push_back(str);
            str.clear();
        }
        if(flag)
        {
            str+=s[i];
        }
        if(s[i]=='{') flag = true;
    }  
    sort(ans.begin(),ans.end(),compare);
    
    set<int> result;
    for(int i=0;i<ans.size();i++)
    {
        stringstream ss(ans[i]);
        string num;
        while (getline(ss, num, ',')) {
            // 분리된 숫자 출력
          int number = stoi(num);
          if(result.insert(number).second) answer.push_back(number);
        }
    }

    
    return answer;
}