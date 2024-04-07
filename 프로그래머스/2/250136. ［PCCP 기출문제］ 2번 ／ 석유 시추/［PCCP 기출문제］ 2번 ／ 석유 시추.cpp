#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;


// 석유덩어리 먼저 저장
// 덩어리를 저장하면서 위치 정보도 같이 해줘야함.
// 먼저 배열을 선언해주고 밑에부분까지 내려가면서 계산
// 만약 위와 아래값이 같다면 아래가 0이아니고 위가 0이 아닐 때는 값을 더해주지 않는다.

int m=0;
int dfs(int x,int y, vector<vector<int>>& Land,vector<vector<bool>>& visited,int _m,
        vector<pair<int,int>>& path)
{    
    // 현재 위치 저장
    path.push_back({y,x});

    if(0<x)
    {
        if(Land[y][x-1]==1 && visited[y][x-1]==false) 
        {             
            visited[y][x-1]=true; dfs(x-1,y,Land,visited,++m,path);
        }
    }
    if(x<Land[0].size()-1)
    {
        if(Land[y][x+1]==1 && visited[y][x+1]==false) 
        {           
            visited[y][x+1]=true; dfs(x+1,y,Land,visited,++m,path); 
        }
    }
    if(0<y)
    {
        if(Land[y-1][x]==1 && visited[y-1][x]==false)
        { 
                       
            visited[y-1][x]=true; dfs(x,y-1,Land,visited,++m,path); 
        }
    }
    if(y<Land.size()-1)
    {
        if(Land[y+1][x]==1 && visited[y+1][x]==false)
        {                                
            visited[y+1][x]=true; dfs(x,y+1,Land,visited,++m,path); 
        }
    }
     
    // 저장한 위치들 m 값으로 바꿔줌

    return m;
}

int solution(vector<vector<int>> land) {
    int answer=0;
    vector<vector<bool>> flag(land.size(),vector<bool>(land[0].size(),false));
    vector<pair<int,int>> path;
    vector<int> landSize(land[0].size(),0);
    
    for(int y=0;y<land.size();y++)
    {
        for(int x=0;x<land[0].size();x++)
        {
            if(land[y][x]!=0&&flag[y][x]==false){
                flag[y][x]=true;
                 m=0;
                dfs(x,y,land ,flag,0,path);
                int size= path.size();
                // 여기서 석유덩어리를 판별해야함.
                set<int> t;
                while(!path.empty())
                {
                    t.insert(path.back().second);
                    land[path.back().first][path.back().second] = size;
                    path.pop_back();
                }

                for(auto it = t.begin();it!=t.end();it++)
                    landSize[*it] +=size;
                
            }
        }
    }
   
    
    for(auto n : landSize) if(answer<n) answer=n;
    
   
    return answer;
}