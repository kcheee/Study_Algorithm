#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
    // 1. 소수 양쪽에 0  => 이건 가운데
    // 2. 소수 오른쪽에 0 왼쪽에 아무것도 없어야 함 =>왼쪽 끝에 자리에서 오른쪽에 0이 나올 때 까지
    // 3. 소수 왼쪽에 0 오른쪽에 아무것도 없어야 함 =>오른쪽 끝에 자리에서 왼쪽에 0이 나올 때 까지
    // 4. 양쪽에 아무것도 없는경우 => 자릿수가 1의 자리밖에 없는 경우

// 소수 판별기 소수면 true
bool decimal(long long n){
    if(n < 2) return false;     
    for(int i=2; i<=sqrt(n); ++i) {
        if(n % i == 0) return false;
    }   
    return true;
}

// 2번,3번 조건의 문자열 cut
string cut(string s)
{
    string ans;
    auto it = s.find('0');
    if(it!=string::npos)
    {
        for(int i=0;i<it;i++)    
            ans+=s[i];         
    }
    else ans =s;
    return ans;
}

int solution(int n, int k) {
    int answer = 0;
    // 진법 계산
    string str;
    while(n!=0)
    {       
        str = to_string(n%k)+str;
        n=n/k;
    } 
    cout<<str<<endl;
    
    // 4번 체크
    if(cut(str)==str) 
    {
        return decimal(stoll(str))==true ? 1 : 0;
    }
    
    // 1번 체크
    // - 첫번째 글자 건너뛰고 마지막 글자도 계산 안해야 함.
    
    bool flag =false;
    string ans1;
    for(int i=0;i<str.size();i++)
    {
        if(flag) 
        {          
            if(str[i] == '0') 
            {
                flag=false;
                if(str[i-1]!='0')                
                answer += decimal(stoll(ans1))==true ? 1 : 0;
                ans1="";
            }
            else ans1+= str[i];                          
        }

        if(str[i] == '0') flag=true;
    }
    
    // 2번 체크
    if(str[0]!='0')
    answer += decimal(stoi(cut(str)))==true ? 1 : 0;
    // 3번 체크
    string str_reverse = str;  reverse(str_reverse.begin(),str_reverse.end());
    if(str_reverse[0]!='0')
    {      
        string s = cut(str_reverse); reverse(s.begin(),s.end());
        answer += decimal(stoll(s))==true ? 1 : 0;
    }
    
    return answer;
}