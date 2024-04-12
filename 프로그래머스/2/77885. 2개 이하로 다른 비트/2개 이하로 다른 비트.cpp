#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

// 뒤에서 계산해서 0이 나온다면 그 값을 1로 바꾸고 뒤에 있는 값은 0으로 바꿔줌.
// 뒤에값이 없거나 0이라면 냅두고 1이라면 0으로 바꿔줌.

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    long long mask = 1;
        
    for(auto n : numbers)
    {
        mask=1;
        for(int i=0;i<64;i++)
        {
            if(i==0 && (n&mask)==0)
            {
                //numbers값에 1만 더해준다.
                answer.push_back(n+1);
                break;
            }
            if((n&mask)!=0)
                mask <<=1;
            
            else
            {          
                long long result = mask + pow(2,i-1);
                answer.push_back(n ^ result);
                break;
            }          
        }    
    }
    
    
    // 1부터 바꾸면 되지
    // mask는 계속 왼쪽으로 shift해줌 
    // and & 연산자 사용 만약 값이 0이 나왔다면 그 뒤에 있는 값과 1을 ^ 연산 해줌.

    
    return answer;
}