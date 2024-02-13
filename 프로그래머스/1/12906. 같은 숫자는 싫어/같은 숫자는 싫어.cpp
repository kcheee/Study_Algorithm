#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    
    // 연속적으로 나타내는 숫자는 제거
    // 배열의 개수만큼 반복문
    // 전에 원소와 다르면 PUSH 아니면 안함.
    
    vector<int> answer;
    
    // 첫번째 원소
    answer.push_back(arr[0]);
    
    for(int i=1; i<arr.size();i++)
    {
        if(arr[i-1]!=arr[i])
            answer.push_back(arr[i]);
    }
    
    return answer;
}