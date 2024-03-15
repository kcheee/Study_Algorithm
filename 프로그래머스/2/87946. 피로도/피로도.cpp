#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 완전 탐색

int solution(int k, vector<vector<int>> dungeons) {
 int answer = 0;
    
    sort(dungeons.begin(), dungeons.end()); // next_permutation을 사용하기 위해 초기 정렬
    do {
        int tempK = k;
        int tempAnswer = 0;
        for(int i = 0; i < dungeons.size(); i++) {
            if(dungeons[i][0] <= tempK) { // 최소 피로도 조건을 만족하면
                tempK -= dungeons[i][1]; // 피로도 감소
                tempAnswer++; // 탐험한 던전 수 증가
            }
        }
        answer = max(answer, tempAnswer); // 최대 탐험 가능한 던전 수 갱신
    } while(next_permutation(dungeons.begin(), dungeons.end()));
    return answer;
}