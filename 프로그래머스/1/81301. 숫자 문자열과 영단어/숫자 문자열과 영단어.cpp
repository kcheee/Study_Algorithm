#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(string s) {
    
    // string 값으로 영어와 숫자가 섞인 값이 들어옴
    // 아스키코드로 설정
    // STL map을 사용해서 key value 값으로 설정해서 만든다
    
    
    // map을 사용해서 영단어로 된 key를 value 저장
    // 만약 아스키코드로 97 122안의 값이 나온다면 숫자가 나올때까지 s_answer에 저장
    // 숫자가 나온다면 s_answer의값을 Key에서 찾고 value값을 답에 더한다.
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
        // 바로 영어가 나오는것도 찾아야함.
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