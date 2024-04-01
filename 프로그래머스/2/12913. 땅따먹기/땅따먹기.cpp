#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// dp 문제

int solution(vector<vector<int>> land)
{
    int answer = 0;
    vector<vector<int>> dp(land.size(), vector<int>(4, 0));
    
    dp[0] = land[0];
    for(int i=1;i<land.size();i++)
    {
        for(int j=0;j<land[0].size();j++)
        {          
            if(j==0) { 
                dp[i][j] = max(dp[i-1][j+1],max(dp[i-1][j+2],dp[i-1][j+3]))+land[i][j];             
                continue; 
            }
            if(j==1) { 
                dp[i][j] = max(dp[i-1][j-1],max(dp[i-1][j+1],dp[i-1][j+2]))+land[i][j];
                continue; 
            }
            if(j==2) { 
                dp[i][j] = max(dp[i-1][j+1],max(dp[i-1][j-1],dp[i-1][j-2]))+land[i][j];
                continue; 
            }
            if(j==3) { 
                dp[i][j] = max(dp[i-1][j-1],max(dp[i-1][j-2],dp[i-1][j-3]))+land[i][j];
                continue; 
            }                    
        }
    }
    
    return *max_element(dp[land.size()-1].begin(),dp[land.size()-1].end());;
}