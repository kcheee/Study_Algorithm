#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

// a y w m 앞 글자가 나온다면 뒷글자를 확인 하는 방법으로 진행
// 반복 진행은 안된다.

int solution(vector<string> babbling) {
    int answer = 0;
  
    string aya = "aya", ye = "ye", woo = "woo", ma = "ma";
    
    for(auto n : babbling)
        for(int i=0;i<n.size();i++)
        {
            if (n[i] == 'a' && i + 2 < n.size()) {  // 'a'를 찾고 그 다음 문자가 존재하는지 확인
                string sub = n.substr(i, 3);
                if(sub == aya)
                {
                    i+=2;
                    if(i==n.size()-1) 
                    {                 
                        answer++;
                    }

                    if(n[i+1]=='a') 
                    {                   
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            if (n[i] == 'y' && i + 1 < n.size()) {  // 'y'를 찾고 그 다음 문자가 존재하는지 확인
                string sub = n.substr(i, 2);
                if(sub == ye)
                {                  
                    i+=1;
                    if(i==n.size()-1) 
                    {
                        
                        answer++;
                    }
                    if(n[i+1]=='y') 
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            if (n[i] == 'w' && i + 2 < n.size()) {  // 'w'를 찾고 그 다음 문자가 존재하는지 확인
                string sub = n.substr(i, 3);
                if(sub == woo)
                {
                    i+=2;
                    if(i==n.size()-1) 
                    {
                        
                        answer++;
                    }

                    if(n[i+1]=='w') 
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            if (n[i] == 'm' && i + 1 < n.size()) {  // 'm'를 찾고 그 다음 문자가 존재하는지 확인
                string sub = n.substr(i, 2);
                if(sub == ma)
                {
                    i+=1;
                    if(i==n.size()-1) 
                    {                       
                        answer++;
                    }
                    if(n[i+1]=='m') 
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            
        }
    
    
    
    return answer;
}