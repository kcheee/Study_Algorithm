#include <iostream>
#include <set>
#include <string>

using namespace std;

int gcd(int a, int b) {
    int r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b) { return (a * b / gcd(a, b)); }

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    // 두 분수의 최소공배수를 구하여 분모 B를 계산
    int B = lcm(b, d);

    // 분자 A는 각 분수의 분자를 공통 분모에 맞게 변환하여 더함
    int A = (a * (B / b)) + (c * (B / d));

    // A와 B를 기약 분수로 만들기 위해 gcd로 나눔
    int G = gcd(A, B);

    // 기약 분수로 변환 후 출력
    cout << A / G << " " << B / G;

    return 0;
}
