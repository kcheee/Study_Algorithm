#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<vector<int>> Map;

void dfs(int x, int y,int size, vector<int>& answer)
{
    bool one,zero;
    one = zero = true;
    
    for(int i=x;i<x+size;i++)
    {
        for(int j=y;j<y+size;j++)
        {
            if(Map[i][j]==0) one = false;
            if(Map[i][j]==1) zero = false;
        }
    }
    
    if(zero) { answer[0]++; return;}
    if(one) { answer[1]++; return;}
    
    dfs(x,y,size/2,answer); // 1사분면
    dfs(x,y+size/2,size/2,answer); // 2사분면
    dfs(x+size/2,y,size/2,answer); // 3사분면
    dfs(x+size/2,y+size/2,size/2,answer); // 4사분면
    
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2,0);
    
    Map = arr;
    dfs(0,0,arr.size(),answer);
    return answer;
}