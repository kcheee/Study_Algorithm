#include <string>
#include <map>
#include <iostream>
#include <cmath>
using namespace std;

// 1. 3번 기회
// 2. 1제곱 ~ 3제곱 (s d t)
// 3. 스타상 : 해당 점수와 전에 얻은 점수 각각 2배로 만듬(첫번째에 나올 경우 첫번째만 두배)
//    아차상 : 해당 점수 마이너스
// 4. 스타상은 중첩됌
// 5. 아차상과도 중첩됌 -2배
// 6. 스타 아차는 점수마다 하나만 존재

// 1~9 47<n<58
int solution(string dartResult) {
    
    
    int answer = 0;
    map<int,int> ans;
    int chance =0;
    for(int i=0;i<dartResult.size();i++)
    {   
        //1~9
        if(dartResult[i]>47 && dartResult[i]<58)
        {
            // 10이 나올 경우
            if(dartResult[i-1]=='1'&&dartResult[i]=='0')     { ans[chance] = 10; continue; }
            chance++; 
            ans[chance] = dartResult[i]-'0';
        }
        else if(dartResult[i]=='D'){  ans[chance]=pow(ans[chance],2); }
        else if(dartResult[i]=='T') ans[chance]=pow(ans[chance],3);
        else if(dartResult[i]=='*') 
        {
            if(chance>1)
            {
                ans[chance]*=2;
                ans[chance-1]*=2;                            
            }
            else ans[chance]*=2;
        }
        else if(dartResult[i]=='#') ans[chance]*=-1;
    }
    
    for(auto n : ans) 
        answer+=n.second;
    
    return answer;
}