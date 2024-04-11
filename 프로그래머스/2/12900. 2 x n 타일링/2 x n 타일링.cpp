#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<long long> dp(n + 1, 0); // 벡터의 크기를 n+1로 설정
    dp[1] = 1; dp[2] = 2;
    
    for(int i = 3; i <= n; i++) // 반복문 조건 수정
    {
        dp[i] = (dp[i-2] + dp[i-1]) % 1000000007;
    }
    return dp[n] % 1000000007;
}
