#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    
    // i번째 숫자부터 j번째까지 자르고 정렬후 k-1번째의 값 [i,j,k]
    
    vector<int> answer;
    vector<int> a;
    for(int i=0;i<commands.size();i++)
    {
        for(int j=commands[i][0]-1;j<commands[i][1];j++)
        {
            // 자르고
            a.push_back(array[j]);
            cout<<array[j];
        }
        // 정렬
        sort(a.begin(),a.end());
        answer.push_back(a[commands[i][2]-1]);
        a.clear();
    }
        
    return answer;
}