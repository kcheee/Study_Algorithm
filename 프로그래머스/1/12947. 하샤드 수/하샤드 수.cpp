#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 자릿수를 나누어 더한 값을 원래의 값에 나누어 떨어지면 하샤드 수

bool solution(int x) {
    bool answer = true;
    int add =0;
    int originX=x;
    while(x){
        add += x%10;
        x=x/10;
    }
    if(originX%add!=0) answer=false;
    
    return answer;
}