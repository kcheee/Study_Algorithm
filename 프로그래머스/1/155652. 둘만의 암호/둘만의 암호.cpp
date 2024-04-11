#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

// skip은 map을 사용해서 인덱스에 바로 접근하는 방식으로

string solution(string s, string skip, int index) {
    string answer = "";
    map<char,bool> m;
    for (auto s : skip) m[s] =true;
    
    for(int i=0;i<s.size();i++)
    {
        char c = s[i];
        vector<char> a;
        int n=1;
        while(a.size()!=index)
        {
            c++;
            if(c>122) c=97;
            
            if(!m[c]) a.push_back(c);
        }
        answer+=a.back();;
    }
    
    return answer;
}