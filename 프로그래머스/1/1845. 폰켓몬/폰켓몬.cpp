#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

    // sort
    // 그냥 배열에 집어 넣는식으로
    // 작은 숫자부터
    //

int solution(vector<int> nums)
{
    map<int,int> a;
    int cnt=0;
    int arr[100001];
    int q=0;
    sort(nums.begin(),nums.end());
    arr[0]=nums[0];
    
    for(int i=1;i<nums.size();i++){
        if(nums[i-1]!=nums[i]) 
        {
            q++;
            arr[q]++;
        }
        else arr[q]++;
    }
    q++;
    
    // 종류가 더 많은 경우
    if(q>=(nums.size()/2)) return nums.size()/2;
    // 아닐경우
    else return q;
    int answer = 0;
    return q;
}