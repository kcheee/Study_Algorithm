#include <string>
#include <vector>
#include <iostream>

using namespace std;

// computer[i][i]는 무조건 1이다.
// 연결이 되어 있다는 포인트가 중요
// 끊어질때 answer++;
// 1. 0번째 네트워크부터 검사
// 2. 재귀를 사용해서 연결되어 있는 네트워크 flag= false 만들어주고 만약 flag가 true라면 return 해준다.
// 3. 다음 연결이 없다는 것을 어떻게 체크하지

bool flag[201] = {false};
vector<vector<int>> test;

void dfs(vector<int>& n,int i)
{
    bool discon = false;
    if(flag[i]==true) 
    {   
        return;
    }
    flag[i] = true;
    for(int j=0;j<n.size();j++)
    {
        if(j==i) continue;
        if(n[j]==1) 
        {            
            if(flag[j]==false)
            {
                dfs(test[j],j);                
            }
        }
    }
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    test = computers;
    
    // 첫번째가 연결이 안되있을 수 있으니 모든 경우의 수를 넣어야 함
    for(int i=0;i<n;i++)
    {
        if(flag[i]==false)
        {
            dfs(computers[i],i);
            answer++; 
        }
    }

    return answer;
}