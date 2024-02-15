#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string t, string p) {
    
    // t를 p의 길이만큼 잘라서 작거나 같은거 비교해서 카운트
    int answer = 0;

    string res;
    
    for(int i=0; i<t.length();i++)
    {        
        for(int j=0;j<p.length();j++)
        {
            res+=t[i+j];
        }
        if(i+p.length()>t.length()) break;           
       
        //res와 p와 비교
        if(stoll(res)<=stoll(p)) answer++;
        res="";
    }
    
    return answer;
}