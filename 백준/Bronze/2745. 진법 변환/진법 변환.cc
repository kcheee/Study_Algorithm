#include <iostream>
#include <string>
#include <cctype>

using namespace std;

long long solution(string n, int b) {
    long long ans = 0;
    int digit, len = n.size();

    for (int i = 0; i < len; ++i) {
        char currentChar = n[i];

        // 알파벳인 경우
        if (isalpha(currentChar))
            digit = currentChar - 'A' + 10;
        else  // 숫자인 경우
            digit = currentChar - '0';

        // 자릿수를 고려하여 계산
        ans = ans * b + digit;
    }

    return ans;
}

int main() {
    string N;
    int B;
    cin >> N >> B;
    cout << solution(N, B) << endl;
    return 0;
}