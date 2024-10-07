#include <iostream>
using namespace std;

int main() {
    int a, b, c, d, e, f;

    // 입력받기
    cin >> a >> b >> c >> d >> e >> f;

    // x와 y의 가능한 범위는 -999 ~ 999이므로 완전 탐색
    for (int x = -999; x <= 999; x++) {
        for (int y = -999; y <= 999; y++) {
            // 두 식을 만족하는 (x, y) 찾기
            if (a * x + b * y == c && d * x + e * y == f) {
                cout << x << " " << y << endl;
                return 0;  // 정답을 찾으면 프로그램 종료
            }
        }
    }

    return 0;
}
