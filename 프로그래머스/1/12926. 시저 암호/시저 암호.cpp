#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, int n) {
    
    // 단어를 하나씩 쪼개서 하나씩 밀어버림
    // 아스키코드 사용
    
    // A =65 Z =90
    // a =97 z =122
    string answer = "";
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==' ') 
        {
            answer+=" ";
            continue;        
        }
        if(64<int(s[i])&&91>int(s[i]))
           {
               int a=int(s[i])+n;
               if(a>90)
               {
                   a=65+a-91;
               }
                answer+= char(a);
           }
        
        if(96<int(s[i])&&123>int(s[i]))
           {
               int a=int(s[i])+n;
               if(a>122)
               {                    
                   a=97+a-123;
               }
                answer+= char(a);
           }
        // 대문자의 경우 91이상일 경우 65로 돌아감 if(i-)
        // 소문자일 경우 123 이상일 경우 97로 돌아감
    }
    return answer;
}