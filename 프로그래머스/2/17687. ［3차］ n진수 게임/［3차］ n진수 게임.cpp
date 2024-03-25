#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

// 진법 n, 미리구할 숫자 개수 t, 인원 m, 튜브의 순서p

// 1. 진법계산기 만들기
// 2. 미리 만들어 놓자!
// 3. t*m 만큼만 만들자.

string decimal(int a,int b,int k)
{
    string res="01";
    int j=2;
    while(res.size()<a*b)
    {
        string s;
        int i=j;
        while(i!=0)
        {
            s = (i % k > 9 ? string(1, (char)(i % k + 55)) : to_string(i % k))+s;
            i/=k;
            
            if(res.size()>a*b) break;
        }
        res+= res.size()+s.size()>a*b ? s.substr(0,a*b-res.size()) : s;
        j++;
    }
    
    return res;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    string ans = decimal(t,m,n);
    for(int i=p-1;i<ans.size();i+=m)
    {      
            answer+=ans[i];
    }
    return answer;
}