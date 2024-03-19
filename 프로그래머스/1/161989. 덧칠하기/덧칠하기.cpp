#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

// n은 칠할 수 있는 총 구간
// m 롤러의 길이

// 제일 첫번째 섹션에 롤러의 왼쪽 부분을 맞추고 pop
// 섹션의 사이즈가 0이 될 때가지 진행

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    queue<int> a;
    for(auto n : section) a.push(n);
    
   while (!a.empty()) {
        int check = a.front() + m;
        while (!a.empty() && a.front() < check) {
            a.pop();
        }
        answer++;
    }   
    return answer;
}