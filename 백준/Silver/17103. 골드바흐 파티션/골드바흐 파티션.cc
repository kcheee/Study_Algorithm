#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1000000;

// 에라토스테네스의 체로 소수를 구하는 함수
void sieve_of_eratosthenes(vector<bool>& is_prime) {
    is_prime[0] = is_prime[1] = false;  // 0과 1은 소수가 아님
    for (int i = 2; i * i <= MAX_N; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX_N; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    // 소수 여부를 저장할 배열
    vector<bool> is_prime(MAX_N + 1, true);
    sieve_of_eratosthenes(is_prime);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        int count = 0;

        // 두 소수의 합으로 N을 만드는 경우의 수 계산
        for (int i = 2; i <= N / 2; ++i) {
            if (is_prime[i] && is_prime[N - i]) {
                count++;
            }
        }

        cout << count << '\n';
    }

    return 0;
}
