#include <vector>
#include <cmath>

using namespace std;

int solution(int n, vector<int> stations, int w) {
    int answer = 0;
    int idx = 1;

    for (int i : stations) {
        if (i - w > idx) {
            answer += ceil(double(i - w - idx) / double(2 * w + 1));
        }
        idx = i + w + 1;
    }

    if (idx <= n) {
        answer += ceil(double(n - idx + 1) / double(2 * w + 1));
    }

    return answer;
}
