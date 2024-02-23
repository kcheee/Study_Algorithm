#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    
   vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> minHeap; // 최소 힙 정의

    for (int i = 0; i < score.size(); ++i) {
        // 처음 k일 동안은 모든 점수를 추가
        if (i < k) {
            minHeap.push(score[i]);
        } else {
            // k일 이후부터는 새로운 점수가 현재 힙의 최소값보다 클 경우에만 처리
            if (score[i] > minHeap.top()) {
                minHeap.pop(); // 현재 힙의 최소값 제거
                minHeap.push(score[i]); // 새로운 점수 추가
            }
        }
        answer.push_back(minHeap.top()); // 매일 최하위 점수를 결과에 추가
    }

    return answer;
}