#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int solution(vector<int> citations) {
    
    // h번
    int answer = 0;
    
    sort(citations.begin(),citations.end(),greater<int>());
    
    for(int i = 0; i < citations.size(); i++) {
        // 현재 인용 횟수가 i+1 이상인지 확인합니다. 
        if(citations[i] >= i + 1) {
            answer = i + 1; // 조건을 만족하면 answer를 업데이트 합니다.
        } else {
            // 더 이상 H-Index 조건을 만족하지 않으면 반복을 종료합니다.
            break;
        }
    }
    return answer;
    // 3 4 5 8 10
}