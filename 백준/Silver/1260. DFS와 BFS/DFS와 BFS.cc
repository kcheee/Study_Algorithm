#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool D_visited[1001];
vector<int> D_graph[1001];
// index 0은 사용하지 않음으로 배열을 하나 더 추가
bool B_visited[1001];
vector<int> B_graph[1001];

void dfs(int x)
{
    sort(D_graph[x].begin(), D_graph[x].end()); // 작은수부터 탐색
    D_visited[x] = true;
    cout << x << " ";
    for (int i = 0; i < D_graph[x].size(); i++) // 인접한 노드 사이즈만큼 탐색
    {
        
        int y = D_graph[x][i];
        if (!D_visited[y]) // 방문하지 않았으면 즉 visited가 False일 때 not을 해주면 True가 되므로 아래 dfs 실행
            dfs(y); // 재귀적으로 방문
    }
}
// BFS 함수 정의
void bfs(int start) {
    queue<int> q;
    q.push(start); // 첫 노드를 queue에 삽입
    B_visited[start] = true; // 첫 노드를 방문 처리
    // 작은수부터 탐색
    // 큐가 빌 때까지 반복
    while (!q.empty()) {
        // 큐에서 하나의 원소를 뽑아 출력
        int x = q.front();
        sort(B_graph[x].begin(), B_graph[x].end());
        q.pop();
        cout << x << " ";
        // 해당 원소와 연결된, 아직 방문하지 않은 원소들을 큐에 삽입
        for (int i = 0; i < B_graph[x].size(); i++) {
            int y = B_graph[x][i];
            if (!B_visited[y]) {
                q.push(y);
                B_visited[y] = true;
            }
        }
    }
}

int main() {

	int n, m,v;
	cin >> n >> m >> v;

    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        D_graph[a].push_back(b);
        B_graph[a].push_back(b);
        D_graph[b].push_back(a);
        B_graph[b].push_back(a);
    }

    dfs(v);
    cout << endl;
    bfs(v);
	

}