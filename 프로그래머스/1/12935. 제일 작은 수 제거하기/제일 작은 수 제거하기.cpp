#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int num=0;
    int point=0;
    if(arr.size()<=1) { 
        answer.push_back(-1);
        return answer;
    }
    answer = arr;
    sort(answer.begin(), answer.end());
    
    num = answer[0];
    answer.erase(answer.begin(),answer.begin()+1);
    
    for(int i =0;i<arr.size();i++)
    {
        if(arr[i]==num) point=i;
    }
    
    arr.erase(arr.begin()+point,arr.begin()+point+1);

    return arr;
}