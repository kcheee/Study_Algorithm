#include <string>
#include <vector>
#include <iostream>


using namespace std;

string solution(string s) {
    
    // 각 단어를 끊고
    // 짝수는 소문자 홀수는 대문자로 바꾼다.
    
    // 공백을 기준으로 문자열을 자른다.
    // s의 길이만큼 반복
    // 공백 발견 시 문자열 자름.
    // 기준선을 a와 b로 잡고 a가 첫번째 b가 마지막으로해서 문장을 나눈다.
    int a=0,b=0;
    string answer = "";
    
    // 1. 기준선 a,b를 기준으로 공백을 발견할 시
    // 2. 멈추고 a에서 b만큼 대문자 소문자 처리 후 answer에 더해줌
    
    // 공백 있는곳이 짝수인가 홀수인가 체크하자
    bool flag = true;
    for(int i=0; i<s.length();i++)
    {
        if(s[i]==' ')
        {
            if(i%2==0)
                flag =false;
            else
                flag =true;
            answer+= " ";
        }
        else
        {
            if(flag)
            {
                if(i%2==0) answer +=toupper(s[i]);
                else answer+=tolower(s[i]);
            }
            else
            {
                if(i%2==0) answer +=tolower(s[i]);
                else answer+=toupper(s[i]);
            }
        }
    }
    
    return answer;
}