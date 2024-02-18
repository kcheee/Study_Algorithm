#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int solution(vector<vector<int>> sizes) {
    
    // a는 가장 큰 숫자
    // b는 가장 작은 숫자 중 큰 숫자
    int answer = 0;
    int a=0,b=0;
    
    for(int i=0;i<sizes.size();i++)
    {        
        if(sizes[i][0]<sizes[i][1])
        {
            iter_swap(sizes[i].begin(), sizes[i].begin() + 1);
                       
            cout<< sizes[i][0]<<":" <<sizes[i][1]<<" ";
        }
        if(a<sizes[i][0]) a=sizes[i][0];
        if(b<sizes[i][1]) b=sizes[i][1];
    }
    answer = a*b;
    return answer;
}