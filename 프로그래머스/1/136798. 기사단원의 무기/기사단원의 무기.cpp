#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    int cnt[100001] = {0}; // 배열을 0으로 초기화
    
    for (int i = 1; i <= 100000; i++) {
        for (int j = 1; j * i <= 100000; j++) {
            cnt[i * j]++; 
        }
    }
    
    for (int i = 1; i <= min(number, 100000); i++) { // number와 100000 중 작은 값까지만 확인
        if (cnt[i] <= limit) {
            answer += cnt[i];
        } else {
            answer += power;
        }
    }
    
    return answer;
}