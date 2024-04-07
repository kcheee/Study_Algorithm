#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<long long>> dp(n, vector<long long>(m, 0)); // 초기값을 0으로 설정
    
    // 물에 잠긴 지역 표시
    for (auto puddle : puddles) {
        dp[puddle[1] - 1][puddle[0] - 1] = -1; // 물에 잠긴 지역은 -1로 표시
    }
    
    // 집 위치 초기값 설정
    dp[0][0] = 1;
    
    // 최단경로 개수 계산
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // 물에 잠긴 지역인 경우 해당 지점의 값을 0으로 설정
            if (dp[i][j] == -1) {
                dp[i][j] = 0;
                continue;
            }
            // 위쪽과 왼쪽의 최단경로 개수를 합산하여 현재 지점의 최단경로 개수를 계산
            if (i > 0) dp[i][j] += dp[i - 1][j] % 1000000007;
            if (j > 0) dp[i][j] += dp[i][j - 1] % 1000000007;
        }
    }
    
    // 최단경로의 개수 반환
    return dp[n - 1][m - 1] % 1000000007;
}
