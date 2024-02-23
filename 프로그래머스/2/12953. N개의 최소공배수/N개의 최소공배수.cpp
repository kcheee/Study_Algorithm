#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 유클리드 호제법

// 유클리드 호제법을 이용한 최대공약수 계산
int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// 최소공배수 계산
int lcm(int a, int b) {
    return a / gcd(a, b) * b; // 오버플로우를 방지하기 위해 순서 주의
}

int solution(vector<int> arr) {
    int result = arr[0]; // 배열의 첫 번째 요소로 초기화

    for (int i = 1; i < arr.size(); i++) {
        result = lcm(result, arr[i]); // 현재까지의 최소공배수와 다음 요소의 최소공배수를 계산
    }

    return result;
}