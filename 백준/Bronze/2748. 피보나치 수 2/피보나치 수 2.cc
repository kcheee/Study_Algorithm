#include <iostream>

using namespace std;

long long dp[90];

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    
    int num;
    cin >> num;
    
    for (int n=4; n < num+1; n++){
        dp[n] = dp[n-1] + dp[n-2];
    }
    
    cout << dp[num] << "\n";

    return 0;
}
