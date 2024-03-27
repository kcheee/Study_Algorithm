#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> maps) {
    int n = maps.size();
    int m = maps[0].size();

    // 방문 여부를 저장할 배열 배열의 크기 설정
    vector<vector<int>> distances(n, vector<int>(m, -1));

    queue<pair<int, int>> q;
    q.push(make_pair(0, 0)); // 시작 지점 추가
    distances[0][0] = 0;

    int dr[] = { 0, 0, 1, -1 };
    int dc[] = { 1, -1, 0, 0 };

    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        // 상대 팀 진영에 도착한 경우 최단 거리 반환
        if (row == n - 1 && col == m - 1) {
            return distances[row][col]+1;
        }
        // 네 방향으로 이동하며 탐색
        for (int i = 0; i < 4; ++i) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            // 새로운 위치가 범위 내에 있고, 벽이 아니며 아직 방문하지 않은 경우 이동
            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                maps[nr][nc] == 1 && distances[nr][nc] == -1) {
                q.push(make_pair(nr, nc));
                distances[nr][nc] = distances[row][col] + 1; // 이동 횟수를 저장
            }
        }
    }

    // 상대 팀 진영에 도착할 수 없는 경우
    return -1;
}
