#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

// 기본 해시 함수 사용
int main() {
    string S;
    cin >> S;

    unordered_set<size_t> set_cnt; // 부분 문자열의 해시 값을 저장할 set
    const int n = S.size();
    
    for (int length = 1; length <= n; ++length) {
        size_t hash = 0;
        size_t prime = 31; // 작은 소수로 해싱
        size_t prime_power = 1;
        
        // 첫 부분 문자열 해시 계산
        for (int i = 0; i < length; ++i) {
            hash = hash * prime + (S[i] - 'a' + 1);
            prime_power *= prime;
        }
        set_cnt.insert(hash); // 첫 해시 삽입

        // 나머지 부분 문자열의 해시를 롤링하면서 계산
        for (int i = 1; i <= n - length; ++i) {
            // 이전 문자 빼고, 다음 문자 더해서 롤링 해시 계산
            hash = (hash * prime) - (S[i - 1] - 'a' + 1) * prime_power + (S[i + length - 1] - 'a' + 1);
            set_cnt.insert(hash);
        }
    }

    cout << set_cnt.size();
}
