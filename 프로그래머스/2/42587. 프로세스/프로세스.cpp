#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;


// 필요한 정보
// 큰 숫자가 몇 개 있는지 체크
// 인덱스 위치 체크
// [인덱스][우선순위]

int solution(vector<int> priorities, int location) {
 int answer = 0; // 인쇄 순서를 저장할 변수
    queue<pair<int, int>> q; // 문서의 인덱스와 우선순위를 저장할 큐
    priority_queue<int> pq; // 우선순위를 저장할 우선순위 큐

    // 큐와 우선순위 큐를 초기화
    for (int i = 0; i < priorities.size(); ++i) {
        q.push({ i, priorities[i] }); // {인덱스, 우선순위}
        pq.push(priorities[i]); // 우선순위
    }

    while (!q.empty()) {
        int idx = q.front().first; // 현재 문서의 인덱스
        int val = q.front().second; // 현재 문서의 우선순위
        q.pop();

        if (val == pq.top()) { // 현재 문서의 우선순위가 가장 높은 경우
            pq.pop(); // 우선순위 큐에서 제거
            ++answer; // 인쇄 순서 증가
            if (idx == location) { // 현재 문서가 찾고 있는 문서인 경우
                break; // 반복문 종료
            }
        } else {
            q.push({ idx, val }); // 현재 문서를 큐의 뒤로 이동
        }
    }

    return answer;
}