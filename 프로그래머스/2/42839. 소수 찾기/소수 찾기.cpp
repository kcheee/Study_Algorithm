#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

// 가장 큰 수를 찾고
// 에라토스테네스의 체를 사용하여 소수 판별

vector<bool> t;
 int answer = 0;
void test(int a)
{
    t.resize(a+1,true);
    
    
    for(int i=2;i*i<=a;i++)
    {
        if(t[i])
        {
            for(int j=i*i;j<=a;j+=i) t[j] = false;
        }
    }
}

void generateSubstrings(string input) {
    set<int> uniqueSubstrings; // 중복을 피하기 위해 set 사용

    // 시작 문자열을 정렬하여 next_permutation을 사용할 준비
    string sortedInput = input;
    sort(sortedInput.begin(), sortedInput.end());

    do {
        // 모든 부분 문자열 생성
        for (size_t i = 0; i < sortedInput.length(); ++i) {
            for (size_t len = 1; len <= sortedInput.length() - i; ++len) {
                uniqueSubstrings.insert(stoi(sortedInput.substr(i, len)));
            }
        }
    } while (next_permutation(sortedInput.begin(), sortedInput.end()));

    // 결과 출력
    for (const auto& substr : uniqueSubstrings) {
        int n = substr;
        if(n==0|| n==1) continue;
        if(t[n]) answer++;
    }
}

int solution(string numbers) {
   
    string maxnum;
    priority_queue<char> que;
    for(auto s : numbers) que.push(s);
    
    while(!que.empty())
    {
        maxnum+=que.top();
        que.pop();
    }
    // 최대값 기준
    test(stoi(maxnum));
    
    
    generateSubstrings(maxnum);

    
    return answer;
}