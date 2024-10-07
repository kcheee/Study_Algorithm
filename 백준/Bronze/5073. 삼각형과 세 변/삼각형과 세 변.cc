#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    while (true) {
        int sides[3];
        cin >> sides[0] >> sides[1] >> sides[2];

        // 종료 조건
        if (sides[0] == 0 && sides[1] == 0 && sides[2] == 0) break;

        // 배열 정렬
        sort(sides, sides + 3);

        // 삼각형 성립 조건 확인
        if (sides[2] >= sides[0] + sides[1]) {
            cout << "Invalid" << endl;
            continue;
        }

        // 삼각형의 종류 판별
        if (sides[0] == sides[1] && sides[1] == sides[2]) {
            cout << "Equilateral" << endl;
        } else if (sides[0] == sides[1] || sides[1] == sides[2] || sides[0] == sides[2]) {
            cout << "Isosceles" << endl;
        } else {
            cout << "Scalene" << endl;
        }
    }
}
