#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <cmath>

using namespace std;

int solution(int n) {
    
    // 1. 3진법
    // 2. 앞뒤 반전
    // 3. 10진법으로 표현
    stack<int> res;
    
    while(n!=0){
        res.push(n%3);
     
        n/=3;
    }    
    int repeat = res.size();
    int answer = 0;
    for(int i=0;i<repeat;i++)
    {
        answer+=res.top()*pow(3,i);
        res.pop();
    }
    

    return answer;
}
