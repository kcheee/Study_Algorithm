#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer=0;
void dfs(vector<int>& numbers, int target, int sum, int index) {
    // 모든 숫자를 탐색했을 때
    if (index == numbers.size()) {
        // 현재까지의 합이 타겟 넘버와 같다면 방법의 수를 증가
        if (sum == target) {
            answer++;
        }
        return;
    }
    
    // 현재 숫자를 더하는 경우
    dfs(numbers, target, sum + numbers[index], index + 1);
    // 현재 숫자를 빼는 경우
    dfs(numbers, target, sum - numbers[index], index + 1);
}

int solution(vector<int> numbers, int target) {

    dfs(numbers,target,0,0);
    return answer;
}