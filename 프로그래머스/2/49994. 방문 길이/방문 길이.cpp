#include <string>
#include <iostream>
#include <set>
// 05:52

using namespace std;

// 방문길이
// 제한길이를 넘어가면 명령어 무시(continue)


// set을 중복제거
// 0,0 -> 0,1

int solution(string dirs) {
    int x=0,y=0;
    set<pair<pair<int,int> ,pair<int,int>>> ans;
    
    for(auto n : dirs)
    {
        pair<int,int> before_xy ={x,y};
        if(n == 'U'&&y<5) y++;              
        else if(n == 'D'&&y>-5) y--;             
        else if(n == 'R'&&x<5)  x++;          
        else if(n == 'L'&&x>-5) x--;       
        
        // 위치를 바꿨을때 
        if(before_xy != pair<int,int>{x,y}&&
           ans.find(make_pair(make_pair(x, y),before_xy))==ans.end())
            ans.insert(make_pair(before_xy, make_pair(x, y)));
    }
    
    for(auto n : ans)
    {
        cout<<n.first.first<<","<<n.first.second<<" "<<n.second.first<<","<<n.second.second<<endl;
    }
    return ans.size();
}