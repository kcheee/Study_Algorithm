#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    
 vector<int> answer;

    // left부터 right까지의 범위를 직접 순회합니다.
    for (long long i = left; i <= right; ++i) {
        // 현재 위치에 해당하는 행과 열을 계산합니다.
        long long row = i / n; // 행 위치
        long long col = i % n; // 열 위치

        // 배열의 규칙에 따라 값이 행과 열의 인덱스 중 더 큰 값으로 결정됩니다.
        // 인덱스는 0부터 시작하므로 1을 더해줍니다.
        long long value = max(row, col) + 1;
        answer.push_back(value);
    }

    return answer;      
}