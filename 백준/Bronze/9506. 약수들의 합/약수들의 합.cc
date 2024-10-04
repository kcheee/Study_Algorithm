#include <iostream>
#include <vector>
using namespace std;

void factor(int n) {
    vector<int> divisors;
    int sum = 0;

    // 1부터 n의 절반까지 약수를 구함
    for (int i = 1; i <= n / 2; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            sum += i;
        }
    }

    // 완전수인 경우 출력
    if (sum == n) {
        cout << n << " = ";
        for (size_t i = 0; i < divisors.size(); ++i) {
            cout << divisors[i];
            if (i < divisors.size() - 1) {
                cout << " + ";
            }
        }
        cout << endl;
    }
    else {
        // 완전수가 아닌 경우
        cout << n << " is NOT perfect." << endl;
    }
}

int main() {
    int n;

    while (true) {
        cin >> n;
        if (n == -1) break;
        factor(n);
    }

    return 0;
}
