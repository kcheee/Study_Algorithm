#include <string>
#include <vector>
#include <iostream>

using namespace std;

    // 짝수면 2로 나눔
    // 홀수면 3곱하고 1더함
    // 1이될때까지 반복
    // 몇번이나 반복해야 하는지 체크.

int solution(int n) {
    int answer = 0;
    long long num =n;
    while(1){
        if(num==1) break;
        
        //짝수라면
        num%2==0?num/=2:num=num*3+1;
                            
        answer++;
        if(answer>=500) return -1;
    }
    cout<<answer;
    return answer;
}