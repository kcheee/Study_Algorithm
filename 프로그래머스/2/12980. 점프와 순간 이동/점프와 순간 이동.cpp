#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    // 2로 나누었을 때 나머지가 발생하면 ans ++ 해줌\
    
    while(n)
    {
        if(n%2!=0) ans++;
        n=n/2;
    }
    
    return ans;
}