#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int a, int b, int n) {
    
    // 빈병 2개 콜라 하나
    // 빈병 a개를 주면 콜라 b병을 주는 마트에서 빈병 n개를 가져다 주면 총 몇 병을 받을 수 있는지
    
    int answer = 0;
    while(n/a!=0)
    {
        answer+= (n/a)*b;
        n= ((n/a)*b)+(n%a);
    }
    
    return answer;
}