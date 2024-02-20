#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(string s) {
    
    map<string,string> m_number;
    
    m_number.insert({"zero","0"});    m_number.insert({"one","1"});    m_number.insert({"two","2"});
    m_number.insert({"three","3"});   m_number.insert({"four","4"});    m_number.insert({"five","5"});
    m_number.insert({"six","6"});    m_number.insert({"seven","7"});    m_number.insert({"eight","8"});
    m_number.insert({"nine","9"});
    
    string s_answer;
    string ans;
    int answer = 0;
    
    for(int i=0;i<s.size();i++)
    {
        // 만약 문자열이 나온다면
        if(int(s[i])>96 && 123>int(s[i]))
        {                
            s_answer += s[i];
            if (m_number.find(s_answer) != m_number.end()) 
	        {
                ans+=m_number[s_answer];
                s_answer.clear();
	        }
        }
        // 숫자이고 전에 영어가 나왔다면 map에서 key값을 찾는다.
        else if(int(s[i-1])>96 && 123>int(s[i-1]))
        {          
           ans += m_number[s_answer]+s[i];         
           s_answer.clear();
        }
        else
        {         
            ans+=s[i];
        }

    }
    answer = stoi(ans);
    return answer;
}