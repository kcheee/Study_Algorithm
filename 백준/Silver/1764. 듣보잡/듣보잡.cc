#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    set<string> unheard;  // 듣도 못한 사람들
    vector<string> result;  // 듣도 보도 못한 사람들 (교집합)

    // 듣도 못한 사람들 입력
    for (int i = 0; i < N; ++i) {
        string name;
        cin >> name;
        unheard.insert(name);
    }

    // 보도 못한 사람들 입력 및 교집합 찾기
    for (int i = 0; i < M; ++i) {
        string name;
        cin >> name;
        if (unheard.find(name) != unheard.end()) {
            result.push_back(name);
        }
    }

    // 사전순으로 정렬
    sort(result.begin(), result.end());

    // 결과 출력
    cout << result.size() << '\n';
    for (const string& name : result) {
        cout << name << '\n';
    }

    return 0;
}
