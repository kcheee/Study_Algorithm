#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 시간 초과

int solution(int n) {
    
    // f(0) = 0
    // f(1) = 1
    // f(n) = f(n-1)+f(n-2)
    // dp 문제
    //
    long long dp[100001];
    dp[0] =0;
    dp[1] =1;
    for(int i=2;i<sizeof(dp)/sizeof(long long);i++)
    {
        dp[i]=(dp[i-1]+dp[i-2])%1234567;
    }
    long long answer = 0;
    answer = dp[n];
    return answer;
}