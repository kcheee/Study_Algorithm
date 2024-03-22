#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int dp[5][5];
    int arr[501]={0};
    int ans[501];   

    
    for(int i=0;i<triangle.size();i++)
    {
        if(i==0)  { ans[0] = triangle[0][0]; arr[0] = triangle[0][0]; continue; }
        
        for(int j=0;j<triangle[i].size();j++)
        {            
            if(j==0)
             ans[j] = triangle[i][j] + arr[0];
            
            else if(j==i)
             ans[j] = triangle[i][j] + arr[j-1];
            
            else
             ans[j] = max(arr[j-1],arr[j])+triangle[i][j];               
        }
        
        for(int k =0;k<=i;k++)
        {
            arr[k] = ans[k];         
        }
    }   
    sort(arr,arr+triangle.size(),greater<int>());
  
    return arr[0];
}