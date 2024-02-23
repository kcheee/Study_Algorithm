#include <iostream>

// n 명이 참가 
// 참가자수 n 참가번호 A, 경쟁번호 B A와 B가 몇라운드에 만나는지

using namespace std;

int solution(int n, int a, int b)
{
  int round = 0;
    while (a != b) {
        a = (a + 1) / 2; // A의 다음 번호
        b = (b + 1) / 2; // B의 다음 번호
        round++; // 라운드 증가
    }
    return round;
}