#include <string>
#include <vector>
#include <iostream>


using namespace std;

string solution(vector<int> food) {
        
// 칼로리가 낮은 음식부터 처먹
// 홀수일 경우 /2
// 0번째는 물
// 칼로리가 적은 순서대로
    
    string answer = "";
    for(int i=1; i<food.size();i++)
    {
        for(int j=0;j<food[i]/2;j++)
        {
            answer+= to_string(i);     
        }
    }
    answer+="0";
    for(int i=food.size()-1; i>0;i--)
    {
        for(int j=0;j<food[i]/2;j++)
        {
            answer+= to_string(i);     
        }
    }
    
    cout<<answer;
    return answer;
}