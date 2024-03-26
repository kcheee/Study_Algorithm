#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
// 야근을 시작한 시점에서 남은 일의 작업량을 제곱하여 더한 값 => 야근 피로도
// works배열에 n을 나누어서 뺐을 때 야근지수가 가장 낮은것
// 일단 높은순으로 sort 무조건 큰 수 부터 뺸다

// * 만약 남은 수가 1이라면 제곱을 해도 1이기 때문에 더 이상 뺴지 않는다.
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    int add =0;
    priority_queue<int> que;
    
    for(auto q : works) add+=q;
    if(add<=n) return 0;
    for(auto k : works) que.push(k);
    
    while(n!=0)
    {
        int value = que.top()-1;
        n--;
        que.pop();
        que.push(value);
        // 맨 위에 있는 값 - 해준다
    }
    while(!que.empty())
    {
        answer+= pow(que.top(),2);
        que.pop();
    }
    
    return answer;
}