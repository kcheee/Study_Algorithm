#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> d, int budget) {
    
    // 부서 별 신청한 금액이 들어있는 배열과 예산
    // 예산을 가지고 최대 줄 수 있는 부서의 개수를 구함.
    
    // 가장 적은 부서 나열한 다음 예산 모자랄 때 까지 예산 소모
    
    int answer = 0;
    sort(d.begin(),d.end());
    
    for(int i=0; i < d.size(); i++)
    {
        budget-=d[i];
        if(budget>=0)
        {
            answer++;
        }
        else
        {
            break;    
        }
    }
    return answer;
}