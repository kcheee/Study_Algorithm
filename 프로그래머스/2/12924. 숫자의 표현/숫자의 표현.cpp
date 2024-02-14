#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    
    // 공식이 있으려나.?
    // 연속된 자연수니깐 그냥 브루트포스 알고리즘
    int answer = 1;
    for(int i=1;i<n+1;i++)
    {
        int a=i;
        int b=i+1;
        while(a<=n)
        {
            a+=b;
            if(a==n)
            {
                cout<<i;
                answer++;
                break;
            }
            b++;
        }
    }
    cout<< ":" << answer ;
    return answer;
}