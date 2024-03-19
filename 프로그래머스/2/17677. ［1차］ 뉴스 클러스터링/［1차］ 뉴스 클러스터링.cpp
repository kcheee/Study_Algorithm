#include <string>
#include <iostream>
#include <set>
#include <algorithm>
#include <map>
using namespace std;
// 03 : 00
// 대소문자 구별 안한다 했으므로 통일 시켜야함.
// ex) transform(check.begin(), check.end(), check.begin(), ::tolower);

// 문자열 두 글자씩 끊는다
// 기타 공백이나 특수 문자가 들어있는 경우 버린다.

// 1. 대소문자 통일
// 2. 문자열 두 글자씩 끊는다(공백이나 특수문자가 포함될 경우 버린다.) <- 이부분은 아스키 코드로 97부터 122까지 소문자
// 3. set을 사용해 교집합 합집합 중복을 막는다.

// map을 사용
// uni에 a의 원소 다 넣고
// b 계산할 때 
int solution(string str1, string str2) {
    int answer = 0;

    map<string,int> a;
    map<string,int> b;
    
    double uni=0;
    double inter=0;
    
    transform(str1.begin(),str1.end(),str1.begin(),::tolower);
    transform(str2.begin(),str2.end(),str2.begin(),::tolower);
    
    for(int i=0;i<str1.size()-1;i++)
    {       
        if( (96<str1[i]&&str1[i]<123) && (96<str1[i+1]&&str1[i+1]<123) )
        {
            string s;  s+= str1[i]; s+=str1[i+1]; 
            a[s]++;
            uni++;
        }      
    } 
    for(int i=0;i<str2.size()-1;i++)
    {
        if( (96<str2[i]&&str2[i]<123) && (96<str2[i+1]&&str2[i+1]<123) )
        {
            string s;  s+= str2[i]; s+=str2[i+1]; 
            b[s]++;
            uni++;
        }
    }
    
    for(auto it =b.begin();it!=b.end();it++)
    {
        if(a[it->first] >0)
        {
            cout<<it->first<<" ";
            // 교집합 및 합집합 계산
            inter += a[it->first] <= it->second ? a[it->first] : it->second;
            uni-= a[it->first] <= it->second ? a[it->first] : it->second;
        }
    }
    double ans=0;
    if(inter == uni ) return 65536;
    ans = double(inter) / double(uni);
  
    return int(ans*65536);
}