#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

bool isprime(int n)
{
    if(n<=1) return false;
    for(int i=2;i*i<=n;i++)
        if(n%i==0) return false;
    return true;
}

int solution(int n) {
    int cnt=0;
    int res[1000001]={0};
    for(int i=1;i<1000001;i++)
    {
        if(isprime(i)) cnt++;
        res[i]=cnt;
    }
    
    return res[n];
}