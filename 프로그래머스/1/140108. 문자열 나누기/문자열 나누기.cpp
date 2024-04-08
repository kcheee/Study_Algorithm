#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    vector<string> ans;
    // x의 개수와 x가 아닌 개수가 같아 질 때 분리
    
    string a;
    char x;
    int c_a=0;
    int c_b=0;
    
    for(auto c : s)
    {
        // a가 비어있을 때
        if(a=="")
        {
            x=c;
            a+=c;
            c_a++;
        }
        else
        {
            // c_a와 값이 같다면 끝내야함.
            if(x!=c)
            {
                c_b++;
                a+=c;
            }
            else
            {
                c_a++;
                a+=c;
            }
            
            if(c_a==c_b) 
            {
                cout<<a<<" ";
                answer++;
                c_b=0;c_a=0;
                a="";
            }
        }
    }
    if(a!="") answer++;
        
    return answer;
}