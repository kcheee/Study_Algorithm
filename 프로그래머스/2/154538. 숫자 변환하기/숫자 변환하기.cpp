#include <queue>
#include <vector>
#include <iostream>
#include <limits.h>

using namespace std;

int solution(int x, int y, int n) {
    if(x==y) return 0;
    int answer = 0;
    vector<bool> visited(y + 1, false); // 방문 여부를 저장하는 배열
    queue<pair<int, int>> q; // BFS를 위한 큐
    q.push({x, 0}); // 시작 위치와 이동 횟수(0)를 큐에 추가
    visited[x] = true; // 시작 위치 방문 처리
    
    while (!q.empty()) {
        int curPos = q.front().first; // 현재 위치
        int curCnt = q.front().second; // 현재 이동 횟수
        q.pop(); // 큐에서 현재 위치와 이동 횟수 정보 제거

        if (curPos == y) { // 목표 위치에 도달한 경우
            answer = curCnt; // 현재 이동 횟수가 최소값이므로 정답에 저장하고 종료
            break;
        }

        // 다음 이동 가능한 위치를 탐색하고 큐에 추가
        if (curPos * 3 <= y && !visited[curPos * 3]) {
            q.push({curPos * 3, curCnt + 1});
            visited[curPos * 3] = true;
        }
        if (curPos * 2 <= y && !visited[curPos * 2]) {
            q.push({curPos * 2, curCnt + 1});
            visited[curPos * 2] = true;
        }
        if (curPos + n <= y && !visited[curPos + n]) {
            q.push({curPos + n, curCnt + 1});
            visited[curPos + n] = true;
        }
    }

    return (answer == 0) ? -1 : answer; // 목표 위치에 도달하지 못한 경우 -1 반환
}
