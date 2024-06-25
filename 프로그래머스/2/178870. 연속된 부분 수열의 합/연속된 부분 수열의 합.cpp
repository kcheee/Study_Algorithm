#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

// 부분 수열의 합은 k
// 여러개인 경우 길이가 짧은 수열
// 길이가 짧은 수열이 여러 개인 경우 앞쪽 에 나오는 수열 

// 투포인트 기법

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2,-1);
    
    int left, right,sum;    left=right=sum=0;
    int minLength= 1000001;
    
    while(sequence.size()>right)
    {
        sum+=sequence[right];
        
        while(sum>k && left<=right)
        {
            sum-=sequence[left];
            left++;
        }
        
        if(sum==k)
        {
            if (right - left + 1 < minLength) 
            {
            minLength = right - left + 1;  
            answer[0] = left;
            answer[1] = right;
            }    
        }     
        right++;
    }
    
    
    return answer;
}